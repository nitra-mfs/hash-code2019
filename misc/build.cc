#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <limits>
#include <cstdint>
#include <string>
#include <fstream>

using namespace std;
using uint = uint32_t;
const uint UMAX = numeric_limits<uint>::max();

// input data + processing

uint R, C, F, N, B, T;
// row, column, fleet, rides, bonus, total time

struct ride {
	uint a, b; // start pos
	uint x, y; // end pos
	uint s; // earliest start
	uint f; // latest finish

	uint length; // total length of the ride
	uint sf; // latest start
	uint gap;
	uint distance() const;
};

vector<ride> rides;

uint absdiff(uint a, uint b)
{
	return a < b ? b-a : a-b;
}

uint distance(uint a, uint b, uint x, uint y)
{
	return absdiff(a, x) + absdiff(b, y);
}

uint ride::distance() const
{
	return ::distance(a, b, x, y);
}


// result
struct vehicle {
	uint x = 0 , y = 0; // current position
	uint t = 0; // current time
	vector<uint>idx;
	uint score(set<uint>&);
	void greedy(set<uint>&);
};

vector<vehicle> vehicles;

template<class In>
In& operator>>(In& in, ride& r)
{
	in >> r.a >> r.b >> r.x >> r.y >> r.s >> r.f;
	r.length = r.distance();
	r.sf = r.f - r.length;
	r.gap = r.sf - r.s;
	return in;
}

template<class Out>
Out& operator<<(Out& out, const ride& r)
{
	out << r.a << " " << r.b << " " << r.x << " " << r.y
	    << " " << r.s << " " << r.f 
	    << "("<< r.length<<"/"<< r.sf << "/" << r.gap << ")";
	return out;
}

template<class Out>
Out& operator<<(Out& out, const vehicle& v)
{
	out << v.idx.size() << " ";
	copy(begin(v.idx), end(v.idx), ostream_iterator<uint>(out, " "));
	return out;
}

void read_input_file(istream& in)
{
	in >> R >> C >> F >> N >> B >> T;
	rides.resize(N);
	for (auto& r: rides)
		in >> r;
}

void write_input()
{
	cout << R << " " << C << " " << F << " " << N << " "
	    << B << " " << T << "\n";
	for (const auto& r: rides) {
		cout << r << "\n";
	}
}

uint vehicle::score(set<uint>& check)
{
	uint score = 0;
	x = y = t = 0;
	for (auto i: idx) {
		auto [it, known] = check.insert(i);
		if (!known) {
			cerr << "Doubly used ride " << i << "\n";
			::exit(1);
		}
		const auto& r = rides[i];
		auto d = distance(x, y, r.a, r.b);
		t += d;
		score += r.length;
		if (t <= r.s) {
			t = r.s;
			score += B;
		}
		t += r.length;
		x = r.x;
		y = r.y;
		if (t > r.f) {
			cerr << "End of ride #" << i << " too late " 
			    << t<< "\n"; 
			::exit(1);
		}
	}
	if (t > T) {
		cerr << "Simulation time exceeded " << t << "\n";
		::exit(1);
	}
	return score;
}


uint full_score()
{
	uint score = 0;

	set<uint> check;

	for (auto& v: vehicles) {
		score += v.score(check);
	}
	return score;
}

void write_output(ostream& out)
{
	for (const auto& v: vehicles)
		out  << v << "\n";
}

bool possible(const ride& r)
{
	uint d = distance(0, 0, r.a, r.b) + r.length;
	if (d > r.f)
		return false;
	else
		return true;
}

uint max_score(const ride& r)
{
	uint d = distance(0, 0, r.a, r.b);
	if (d + r.length > r.f)
		return 0;
	else if (d <= r.s)
		return B + r.length;
	else
		return r.length;
}

uint max_score()
{
	uint s = 0;
	for (const auto& r: rides)
		s += max_score(r);
	return s;
}

void greedy(set<uint>& avail)
{
	while (true) {
		vehicle *bestv = nullptr;
		uint bestr = UMAX;
		float bestvalue = 1e10;
		for (auto& v: vehicles)
			for (auto i: avail) {
				auto& r = rides[i];
				auto d = distance(v.x, v.y, r.a, r.b);
				if (v.t + d + r.length > r.f)
					continue;
				if (v.t + d <= r.s) {
					bonus = b;
					temps = r.s - v.t + r.length;
					score = r.length;
				} else {
					bonus = 0;
					temps = d + r.length;
					score = r.length;
				}

				float s = f(bonus, temps, score);
				if (s < bestvalue) {
					bestvalue = s;
					bestr = i;
					bestv = &v;
				}
			}
		if (bestv) {
			auto& myv = *bestv;
			auto& r = rides[bestr];
			myv.idx.push_back(bestr);
			avail.erase(bestr);
			myv.t += distance(myv.x, myv.y, r.a, r.b);
			if (myv.t < r.s)
				myv.t = r.s;
			myv.t += r.length;
			myv.x = r.x;
			myv.y = r.y;
			continue;
		}
		return;
	}
}

void greedy()
{
	// make all rides available
	set<uint> available;
	for (uint i = 0; i != rides.size(); i++)
		if (possible(rides[i]))
			available.insert(i);

	greedy(available);
	if (available.empty())
		cout << "All possible rides accounted for\n";
	else {
		cout << "Rides left: " << available.size() << "\n";
	}
}

int
main(int argc, char *argv[])
{
	
	if (argc < 2)
		::exit(1);
	string s = argv[1];

	ifstream in(s);
	cout << "Reading: " << s << "\n";
	read_input_file(in);
//	write_input();
	cout << "Max score: " << max_score() << "\n";
	vehicles.resize(F);
	greedy();
	string s2 = s.substr(0, s.find(".in"));
	string s3 = argv[0];
	s3 = s3.substr(s3.find("/")+1);
	s2 = s3 + "-" + s2 + ".out";
	ofstream out(s2);
	write_output(out);
	cout << full_score() << "\n";
	cout << "------------------\n";
}
