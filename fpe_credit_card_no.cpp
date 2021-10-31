#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

// **********************************
// Function to Tweak the Plain Text
// **********************************
string plain_tweak(string plain_txt, string tweak_digits)
{
	string out;
    int sum,ones;
    string ones_s = "";

    for (int i=0; i<6; i++)
    {
        sum = stoi(plain_txt.substr(i, 1)) + stoi(tweak_digits.substr(i, 1));
        ones = sum%10;
        ones_s = to_string(ones);
        out = out + ones_s;

    }
    return out;
}

// ******************************************
// Function to get the Plain Text from Tweak
// ******************************************
string tweak_plain(string plain_tweak, string tweak_digits)
{
    int sum,ones,first;
    string out = "";
    string diff ;

    for (int i=0; i<6; i++)
    {


        int first = stoi(plain_tweak.substr(i, 1));
        int second = stoi(tweak_digits.substr(i, 1));

        if(first >= second)
           {
               first;
           }
        else
           {
                first = first + 10;
           }

        diff = to_string(first - second);

        out = out + diff;

    }
    return out;
}

// ******************************************
// Validate whether given values are number
// ******************************************
bool isNumber(const string& str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}


// ******************************************
// Converting String to Binary
// ******************************************
string strToBinary(string s)
{
    int n = s.length();
    string bits_o = "";
    string z;

    for (int i = 0; i < n; i++)
    {
        // convert each char to
        // ASCII value
        int val = int(s[i]);

        // Convert ASCII value to binary
        string bits = "";
        while (val > 0)
        {
            (val % 2)? bits.push_back('1') :
            bits.push_back('0');
            val /= 2;
        }
        reverse(bits.begin(), bits.end());


        if(bits.size() != 8)
        {
            int r;
            r = 8 - bits.size();
            z = "";
            for (int j = 1; j<=r; j++)
            {
                z = z + "0";
            }
        }

        bits_o = bits_o + z + bits;
    }
    return bits_o;
}

// ******************************************
// Expansion Permutation 32 bits to 48 bits
// ******************************************
string bin_32_48(string bin_32)
{
    string bin_48;
    string bin_32_48_1, bin_32_48_2 ,bin_32_48_3 , bin_32_48_4 , bin_32_48_5 , bin_32_48_6 , bin_32_48_7 , bin_32_48_8;
    bin_32 = "0" + bin_32;
    bin_32_48_1 = bin_32.substr(32,1) + bin_32.substr(1,4) + bin_32.substr(5,1);
    bin_32_48_2 = bin_32.substr(4,1) + bin_32.substr(5,4) + bin_32.substr(9,1);
    bin_32_48_3 = bin_32.substr(8,1) + bin_32.substr(9,4) + bin_32.substr(13,1);
    bin_32_48_4 = bin_32.substr(12,1) + bin_32.substr(13,4) + bin_32.substr(17,1);
    bin_32_48_5 = bin_32.substr(16,1) + bin_32.substr(17,4) + bin_32.substr(21,1);
    bin_32_48_6 = bin_32.substr(20,1) + bin_32.substr(21,4) + bin_32.substr(25,1);
    bin_32_48_7 = bin_32.substr(24,1) + bin_32.substr(25,4) + bin_32.substr(29,1);
    bin_32_48_8 = bin_32.substr(28,1) + bin_32.substr(29,4) + bin_32.substr(1,1);
    bin_32 = bin_32.substr(1,32);

    bin_48 = bin_32_48_1 + bin_32_48_2 +bin_32_48_3 + bin_32_48_4 + bin_32_48_5 + bin_32_48_6 + bin_32_48_7 + bin_32_48_8;

    return bin_48;
}

// *************************
// Permutation Choice 1
// *************************
string Per_ch1(string bits_64)

{
    string Per_ch1;
    bits_64 = "0" + bits_64;

    int ip[57] = {0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,\
                    10,2,59,51,43,35,27,19,11,3,60,52,44,36,\
                    63,55,47,39,31,23,15,7,62,54,46,38,30,22,\
                    14,6,61,53,45,37,29,21,13,5,28,20,12,4};

    Per_ch1 = "";
    for (int i = 1;i<=56;i++)
    {
        Per_ch1 = Per_ch1 + bits_64.substr(ip[i],1);
    }
    bits_64 = bits_64.substr(1,64);
    return Per_ch1;
}

// *************************
// Permutation Choice 2
// *************************
string Per_ch2(string bits_56)

{
    string Per_ch2;
//    cout << bits_56 << endl;
//    cout << bits_56.size() << endl;
    bits_56 = "0" + bits_56;

    int ip[49] = {0,14,17,11,24,1,5,3,28,15,6,21,10,\
                    23,19,12,4,26,8,16,7,27,20,13,2,\
                    41,52,31,37,47,55,30,40,51,45,33,48,\
                    44,49,39,56,34,53,46,42,50,36,29,32};

    Per_ch2 = "";
    for (int i = 1;i<=48;i++)
    {

        Per_ch2 = Per_ch2 + bits_56.substr(ip[i],1);
    }
    bits_56 = bits_56.substr(1,56);

    return Per_ch2;
}

// *********************
// Left Circular Shift
// *********************
string left_cir_shift(string left_key_28,int shift)
{
    string first_bit,left_key_lcs,left_key_out;
    left_key_lcs = "";
    left_key_out = left_key_28;
    for (int i=1;i<=shift;i++)
    {
        first_bit = left_key_out.substr(0,1);
        left_key_lcs = left_key_out.substr(1,27) + first_bit;
        left_key_out = left_key_lcs;
    }
    return left_key_out;
}

// ***************************
// Convert Decimal to Binary
// ***************************
string decimaltoBinary(int CCN)
{
	string bits;
	while (CCN != 0)

	{
		bits = (CCN % 2 == 0 ? "0" : "1") + bits;
		CCN = CCN / 2;
	}
	while (bits.length() < 4) {
		bits = "0" + bits;
	}

	return bits;
}

// ***************************
// Convert Binary to Decimal
// ***************************
int binarytoDecimal(string bits)
{
		int cnt = 0, num = 0;;
		int size = bits.length();
		int i = size - 1;
		while(i>=0)
		{
			if (bits[i] == '1')
			{
				num = num + pow(2, cnt);
			}
			cnt+=1;
			i -= 1;
		}
		return num;
}

// *************
// XOR function
// *************

string xor_func(string key, string right)
{
    int k,r;
    string output = "";
    for (int i= 0;i<key.size();i++)
    {
        k = stoi(key.substr(i,1));
        r = stoi(right.substr(i,1));
        output = output + to_string(k^r);
    }
    return output;
}

// **********************
// SBox and Permutation
// **********************
string sbox_per(string right_bit_xor)

{


	/***************************************
	Sbox Table [sbox number] [row ] [column]
	****************************************/
	int sbox[8][4][16] = {

	//**********************
	//sbox 1 table
	//**********************
        {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},
/*    string s1[4][16] ={"1110", "0100", "1101", "0001", "0010", "1111", "1011", "1000", "0011", "1010", "0110", "1100", "0101", "1001", "0000", "0111",
                    "0000", "1111", "0111", "0100", "1110", "0010", "1101", "0001", "1010", "0110", "1100", "1011", "1001", "0101", "0011", "1000",
                    "0100", "0001", "1110", "1000", "1101", "0110", "0010", "1011", "1111", "1100", "1001", "0111", "0011", "1010", "0101", "0000",
                    "1111", "1100", "1000", "0010", "0100", "1001", "0001", "0111", "0101", "1011", "0011", "1110", "1010", "0000", "0110", "1101"}; */

	// **********************
    // sbox 2 table
	// **********************
        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
/*    string s2[4][16] ={"1111", "0001", "1000", "1110", "0110", "1011", "0011", "0100", "1001", "0111", "0010", "1101", "1100", "0000", "0101", "1010",
                    "0011", "1101", "0100", "0111", "1111", "0010", "1000", "1110", "1100", "0000", "0001", "1010", "0110", "1001", "1011", "0101",
                    "0000", "1110", "0111", "1011", "1010", "0100", "1101", "0001", "0101", "1000", "1100", "0110", "1001", "0011", "0010", "1111",
                    "1101", "1000", "1010", "0001", "0011", "1111", "0100", "0010", "1011", "0110", "0111", "1100", "0000", "0101", "1110", "1001"}; */
	// **********************
    // sbox 3 table
	// **********************
		{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
/*    string s3[4][16] ={"1010", "0000", "1001", "1110", "0110", "0011", "1111", "0101", "0001", "1101", "1100", "0111", "1011", "0100", "0010", "1000",
                    "1101", "0111", "0000", "1001", "0011", "0100", "0110", "1010", "0010", "1000", "0101", "1110", "1100", "1011", "1111", "0001",
                    "1101", "0110", "0100", "1001", "1000", "1111", "0011", "0000", "1011", "0001", "0010", "1100", "0101", "1010", "1110", "0111",
                    "0001", "1010", "1101", "0000", "0110", "1001", "1000", "0111", "0100", "1111", "1110", "0011", "1011", "0101", "0010", "1100"}; */
	// **********************
    // sbox 4 table
	// **********************
		{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
/*string s4[4][16] ={"0111", "1101", "1110", "0011", "0000", "0110", "1001", "1010", "0001", "0010", "1000", "0101", "1011", "1100", "0100", "1111",
                    "1101", "1000", "1011", "0101", "0110", "1111", "0000", "0011", "0100", "0111", "0010", "1100", "0001", "1010", "1110", "1001",
                    "1010", "0110", "1001", "0000", "1100", "1011", "0111", "1101", "1111", "0001", "0011", "1110", "0101", "0010", "1000", "0100",
                    "0011", "1111", "0000", "0110", "1010", "0001", "1101", "1000", "1001", "0100", "0101", "1011", "1100", "0111", "0010", "1110"}; */

	// **********************
    // sbox 5 table
	// **********************
		{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
/*string s5[4][16] ={"0010", "1100", "0100", "0001", "0111", "1010", "1011", "0110", "1000", "0101", "0011", "1111", "1101", "0000", "1110", "1001",
                    "1110", "1011", "0010", "1100", "0100", "0111", "1101", "0001", "0101", "0000", "1111", "1010", "0011", "1001", "1000", "0110",
                    "0100", "0010", "0001", "1011", "1010", "1101", "0111", "1000", "1111", "1001", "1100", "0101", "0110", "0011", "0000", "1110",
                    "1011", "1000", "1100", "0111", "0001", "1110", "0010", "1101", "0110", "1111", "0000", "1001", "1010", "0100", "0101", "0011"};*/
	// **********************
    // sbox 6 table
	// **********************
		{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
/*string s6[4][16] ={"1100", "0001", "1010", "1111", "1001", "0010", "0110", "1000", "0000", "1101", "0011", "0100", "1110", "0111", "0101", "1011",
                    "1010", "1111", "0100", "0010", "0111", "1100", "1001", "0101", "0110", "0001", "1101", "1110", "0000", "1011", "0011", "1000",
                    "1001", "1110", "1111", "0101", "0010", "1000", "1100", "0011", "0111", "0000", "0100", "1010", "0001", "1101", "1011", "0110",
                    "0100", "0011", "0010", "1100", "1001", "0101", "1111", "1010", "1011", "1110", "0001", "0111", "0110", "0000", "1000", "1101"}; */

	// **********************
    // sbox 7 table
	// **********************
		{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
/*string s7[4][16] ={"0100", "1011", "0010", "1110", "1111", "0000", "1000", "1101", "0011", "1100", "1001", "0111", "0101", "1010", "0110", "0001",
                    "1101", "0000", "1011", "0111", "0100", "1001", "0001", "1010", "1110", "0011", "0101", "1100", "0010", "1111", "1000", "0110",
                    "0001", "0100", "1011", "1101", "1100", "0011", "0111", "1110", "1010", "1111", "0110", "1000", "0000", "0101", "1001", "0010",
                    "0110", "1011", "1101", "1000", "0001", "0100", "1010", "0111", "1001", "0101", "0000", "1111", "1110", "0010", "0011", "1100"};*/
	// **********************
    // sbox 8 table
	// **********************
		{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
/*string s8[4][16] ={"1101", "0010", "1000", "0100", "0110", "1111", "1011", "0001", "1010", "1001", "0011", "1110", "0101", "0000", "1100", "0111",
                    "0001", "1111", "1101", "1000", "1010", "0011", "0111", "0100", "1100", "0101", "0110", "1011", "0000", "1110", "1001", "0010",
                    "0111", "1011", "0100", "0001", "1001", "1100", "1110", "0010", "0000", "0110", "1010", "1101", "1111", "0011", "0101", "1000",
                    "0010", "0001", "1110", "0111", "0100", "1010", "1000", "1101", "1111", "1100", "1001", "0000", "0011", "0101", "0110", "1011"};*/

			};
        string rest = "";
        while (right_bit_xor.size() > 6)
        {
            string local = "";
            string r_bit = "";
            local = local + right_bit_xor.substr(right_bit_xor.size() - 2, right_bit_xor.size() % 6);
            rest = local + rest;
            right_bit_xor = right_bit_xor.substr(0, right_bit_xor.size() - local.size());
            int k = 0;
            int six_bit;


            // ***********************************
            // Each 8 bits are reduced to 6 bits
            // ***********************************
            while (k < right_bit_xor.size()/6)
            {
                six_bit = k*6;
            //************************************
            // First and Last bits constitute Row
            //************************************
                string row = right_bit_xor.substr(six_bit, 1) + right_bit_xor.substr(six_bit+5, 1);
                string col_s = "";
                string col = "";
            // ***************************************
            // inbetween four bits constitute Column
            // ***************************************
                for (int z=1; z < 5; z++)
                {
                    col_s = right_bit_xor.substr(six_bit + z, 1);
                    col += col_s;
                }
            // ******************************
            // Picking the item from S-Box
            // ******************************
                int sbox_item = sbox[k][binarytoDecimal(row)][binarytoDecimal(col)];
                r_bit = r_bit + decimaltoBinary(sbox_item);
                k += 1;
            }
            right_bit_xor = "";
//                                                                            cout <<"r_bit " <<r_bit<<endl;
            right_bit_xor = right_bit_xor + r_bit;

        }
        right_bit_xor = right_bit_xor + rest;
	//                    cout <<"right_bit_xor " <<right_bit_xor<<endl;

	return right_bit_xor;
}


// ******************************
// Padding to the given bits
// ******************************
string pad_str_f(int pad)
{
    string str_pad = "";
	int p = 0;
	while(pad > p)
	{
		str_pad = str_pad + '0';
		p = p + 1;
	}

	return str_pad;

}

// ******************************
// Fiestal Structure
// ******************************
string Fiestal_Struct(string CCN, string* key_sub, int tweaked_num)
{
    //*******************************
    // Tweaked Number is Encrypted
    //*******************************
	cout << "Tweaked num :" << tweaked_num << endl;
	string bits_enc;

    // ***********************************
    // Converting tweaked_num into bits
    // ***********************************

    int x = 20;
	bits_enc = decimaltoBinary(tweaked_num);
	int pad = x - bits_enc.size();

    // *****************************************
    // Appending pads since our bits are less
    // *****************************************
	bits_enc = pad_str_f(pad) + bits_enc;


    // ************************************************
    // Appending pads since our bits are less than 64
    // ************************************************
	string left_bit = bits_enc.substr(0, 10);
	string right_bit = bits_enc.substr(10, 10);

	cout << "LHS : " << left_bit << "  " <<"RHS : " << right_bit << endl;

    // ************************************************
	// Adding 22 bits to make the right_bit 32 bits
    // ************************************************
	string pad22_zero = "0000000000000000000000";

    // ***************************************************
	// For DES, Fiestel Should be run for 16 rounds each
    // ***************************************************
	int r = 0;
	while (r < 16)
	{
		string right_bit_zero_pre;
		right_bit_zero_pre = pad22_zero + right_bit;
		string Exp_48 = "", right_bit_xor = "";

			// ***************************************************
			// Function is get from XOR of Expansion and Key
			// ***************************************************
				Exp_48 = bin_32_48(right_bit_zero_pre);
				// ***************************************
				// XOR with the Expanded right with key
				// ***************************************

				right_bit_xor = xor_func(Exp_48, key_sub[r]);
				// cout<<"right_bit_xor.size()"<<right_bit_xor<<endl;

				// **************************
				// S-box and Permutation
				// **************************
				right_bit_xor = sbox_per(right_bit_xor);
//                    cout <<"right_bit_xor " <<right_bit_xor<<endl;
		// ************************************
		// XOR Function Left side and Function
		// ************************************
		string left_side_xor = xor_func(right_bit_xor, left_bit);


	// **********************************
	// Shifting the Right and Left bits
	// **********************************
		if (r < 16)
        {
			string lun = right_bit;
			right_bit = left_side_xor;
			left_bit = lun;
		}
		cout << "Round : "<< r + 1<< endl;
		cout << "LHS : " << left_bit << "  " <<"RHS : " << right_bit << endl;
		// *************
		// Next Round
		// *************
		r += 1;
	}


	//***********************************************
	// Combining the Right Side and Left Side bits
	//***********************************************
	return right_bit + left_bit;
}




//**************************
// Main Program Starts Here
//**************************

int main()
{

	//**************************************
	// Getting Credit Card Number from User
	//**************************************
	string CCN;
	while(CCN.size() != 16)
	{
		cout << "Enter your 16 digit Credit Card Number : ";
		cin >> CCN;
		cout << "The length of the given CNN is: " << CCN.size() << endl;
	//****************************************************
	// Check Whether has any Characters other tha numbers
	//****************************************************
		if ( not (isNumber(CCN)))
		{
			cout << "Enter only Numeric values. "<<endl;
			continue;
		}

		cout << CCN<< endl;
	}

	string plain_text;

	string inverse_key_sub[16];
    string left,right, left_key_28, right_key_28;
    string bits_key_64, Per_ch1_56,Per_ch2_48;
    string left_key_lcs,right_key_lcs;
    int shift, k = 0;

    string key = " ";

	//**************************************
	// Getting Credit Card Number from User
	//**************************************
	while(key.size() != 8)
	{
		cout<<"***********************************************"<<endl;
		cout << "* Enter 8 characters of AlphaNumeric key value   \n";
		cout << "* Example : gobinath, cryp1234, 87654321 \n";
		cout << "* 8 bytes converted to 8*8=64 bits in program    \n";
		cout<<"***********************************************"<<endl;
		cout << " Enter 8 characters of AlphaNumeric key value : " ;
		cin >> key;
		cout << "The length of the given Key is: " << key.size() << " bytes"<< endl;
	}

	cout << "Key entered : "<<key<< endl;

	//**********************
	// Keys for 16 rounds
	//**********************
    string key_sub[15] = {};

    bits_key_64 = strToBinary(key);
    cout<<"64 bits Master key : "<<bits_key_64<<endl;

	//**********************
	// Permutation Choice 1
	//**********************
    Per_ch1_56 = Per_ch1(bits_key_64);

	//********************************
	// Left 28 bits and Right 28 bits
	//********************************
    left_key_28 = Per_ch1_56.substr(0,28);
    right_key_28 = Per_ch1_56.substr(28,28);
    cout<<"left_key_28  :"<<left_key_28<<endl;
    cout<<"right_key_28 :"<<right_key_28<<endl;


	//********************************
	// Key Generation for 16 Rounds
	//********************************
	int i = 0;
	while (i <= 15 )
    {
//        cout<<i<<endl;

		//***************************************************
		// We do 2 Left Circular Shift for 1,2,8,16th Rounds
		//***************************************************
        if(i== 0 or i == 1 or i==8 or i==15)
        {
            shift = 1;
        }
        else
        {
            shift = 2;
        }


		//****************************
		// Doing Left Circular Shift
		//****************************
        left_key_lcs = left_cir_shift(left_key_28,shift);
        right_key_lcs = left_cir_shift(right_key_28,shift);

		//*******************************
		// Apply Permutation Choice two
		//*******************************
        Per_ch2_48 = Per_ch2(left_key_lcs + right_key_lcs);

		//*********************
		// Save it as Sub-Key
		//*********************
        key_sub[i] = Per_ch2_48;

        cout<<"key_sub "<< i <<" : "<<key_sub[i]<<endl;

		//****************************************
		// Keep the Shifted Values for Next Round
		//****************************************
        left_key_28 = left_key_lcs;
        right_key_28 = right_key_lcs;
		i = i + 1;
    }


	//**************************************
	// Reversing the subkeys for Decryption
	//**************************************
	for (int b =15; b >= 0; b--)
	{
		inverse_key_sub[k++] = key_sub[b];
	}


	//*************************************
	// Tweak, Plaintext, PlainText + Tweak
	//*************************************

	plain_text = CCN.substr(6,6);
	string tweak_digits = CCN.substr(0,3) + CCN.substr(13,3);

	int tweaked_num = stoi(plain_tweak(plain_text,tweak_digits));


	cout<<"Tweak : " << "First 3 digits from CCN" << endl;
	cout<<"Plaintext : " << "Six Digits from 7 to 12" << endl;
	cout<<"Plaintext + Tweak : " << "Ones of Addition of Tweak and Plaintext" << endl;

	cout << "Original Plain text :" << plain_text << endl;
	cout << "Tweaked Plain text to Encrypt :" << tweaked_num << endl;

	//********************************************************
	// Calling the Fiestal Structure to Encrypt the Plaintext
	//********************************************************
	int enc_num = binarytoDecimal(Fiestal_Struct(CCN, key_sub, tweaked_num));

	cout << "Encrypted_number :" << enc_num << endl;
	cout << "**********************************************************"<<endl;
	cout << "**********************************************************"<<endl;
	cout << "* Encrypted Credit Card Number : " << CCN.substr(0,6) << \
	enc_num << CCN.substr(12,6) <<endl;
	cout << "**********************************************************"<<endl;
	cout << "**********************************************************"<<endl;

	//*************************************************************
	// Calling the Fiestal Structure to Encrypt the Decrpyted Data
	//*************************************************************
	int decrypt_value = binarytoDecimal(Fiestal_Struct(CCN, inverse_key_sub, enc_num));

	cout<<"\n\n"<<endl;
	cout << "Decrypted Tweaked Number :" << decrypt_value << endl;
	cout << "-- EQUAL to Tweaked Plaintext Number Before Encryption --" << endl;
	cout<<"\n"<<endl;

    string Tweak = CCN.substr(0, 3) + CCN.substr(13, 3);
    string original = tweak_plain(to_string(decrypt_value),Tweak);


	cout<<"Tweak : " << "First 3 digits from CCN" << endl;
	cout<<"Plaintext : " << "Six Digits from 7 to 12" << endl;
	cout<<"Plaintext + Tweak : " << " Diff of Digits of Plaintext_Tweak Digits of Tweak " << endl;

	cout << " Converted Original Plain text :" << original << endl;
	cout << "**********************************************************"<<endl;
	cout << "**********************************************************"<<endl;
	cout << "* Decrypted Credit Card Number : " << CCN.substr(0,6) << \
	original << CCN.substr(12,6) <<endl;
	cout << "**********************************************************"<<endl;
	cout << "**********************************************************"<<endl;
		cout << "-- Decrpyted credit card number is EQUAL to the Given Credit Card Number --" << endl;

	system("pause");
	return 0;
}
