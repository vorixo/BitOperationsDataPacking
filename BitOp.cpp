#include <iostream>
#include <stdint.h>
using namespace std;

// In a real scenario this can be used to define when a team is empty or not without
#define team0 0x00000001
#define team1 0x00000002
#define team2 0x00000004
#define team3 0x00000008
#define team4 0x00000010
#define team5 0x00000020
#define team6 0x00000040
#define team7 0x00000080

uint32_t team(0);

void SetDefaultTeamValues() {
	// these teams will be occupied
	team |= team1;
	team |= team3;
	team |= team5;
	team |= team7;
}

void realScenario() {
	SetDefaultTeamValues();
	int desiredTeam(-1);

	while(1) {
		desiredTeam = -1;
		while(desiredTeam > 7 || desiredTeam < 0) {
			cout << "Insert the team you want to get in (0-7): ";
			cin >> desiredTeam;
		}
		
		// move a single bit desiredTeam positions to the left and compare it with the team
		if(team & (1 << desiredTeam)) {
			cout << "Full team" << endl;
		} else {
			cout << "Empty team" << endl;
		}
	}
}



int main() {
	// swap bit: myvar ^= hex_val;
	// bit to 0: myvar &= ~hex_val;
	// bit to 1: myvar |= hex_val;
	// check a bit: bool(myvar & hex_val)
	int myvar(0);
	
	// 0000 0001 <- hex sets the first bit to 1
	// 0000 0000 0000 0001
	myvar ^= 0x00000001;
	cout << "myvar ^= 0x00000001;" << endl;
	
	// 0000 0002 <- hex sets the second bit to 1
	// 0000 0000 0000 0010
	myvar ^= 0x00000002;
	cout << "myvar ^= 0x00000002;" << endl;
	
	// Printing 2nd bit
	cout <<  "Second bit value : " << bool(myvar & 0x00000002) << endl;
	// Printing 3rd bit
	cout <<  "Third bit value : " << bool(myvar & 0x00000004) << endl;
	
	
	// 0000 0004 <- hex sets the thrid bit to 1
	// 0000 0000 0000 0100
	myvar ^= 0x00000004; 
	
	// be careful, if you do 3 in hex it will result on 0000 0000 0000 0011 and you won't be able to sum bits
	
	// 0000 0008 <- hex sets the thrid bit to 1
	// 0000 0000 0000 1000
	myvar ^= 0x00000008; 
	
	// Printing current hex value,should be F
	cout << "Filling myvar with 1s" << endl;
	printf("%08X\n", myvar);
	
	// storing all the bits moved the left 4 positions in other variable
	// from : 0000 0000 0000 1111
	// to   : 0000 0000 1111 0000
	int myothervar(0);
	myothervar =  myvar << 4; 
	cout << "myothervar =  myvar << 4; " << endl;
	printf("%08X\n", myothervar);
	
	// Now if we do an sum operation of both variables it will result on
	// 0000 0000 1111 1111
	// 0000 00FF
	cout << "myothervar +  myvar" << endl;
	printf("%08X\n", myothervar + myvar);
	
	realScenario();
	
}
