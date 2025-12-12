#include <bits/stdc++.h>
using namespace std;

static string Decode(string d);

string text = 
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uCi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4tOi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLgou"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uQEBAQEAlIyVAQEBAJS4uLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4KLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4u"
"LkBAQCMjIyMjIyMjIyMjI0BAQC4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uCi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi5AQEAjIyMjIyMjIyMjIyMjIyMjIyVAQC4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLgouLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLkBAJSMj"
"IyMjIyMqIyMjIyMqIyMjIyMjKiVAQC4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4KLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4qQEAjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjI0BALi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uCi4uLi4uLi4uLi4uLi4uLi4uLi4uLiVAQCMjIyMjI0BA"
"IyMjIyMjIyMjIyMjIyMjIyMjIyMjJUBALi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLgouLi4u"
"Li4uLi4uLi4uLi4uLi4uQEBAIyMjIyMjIyVAJSMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjQEAuLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4KLi4uLi4uLi4uLi4uKkBAQC5AQEAjIyMqIyMjIyVAJSMj"
"IyMjIyMjIyMjIyMjIyMjIyMjIyMjIyNAQC4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uCi4uLi4u"
"Li4uLiNAJSouLjpAQEAjIyMjIyMjIyNAQCMqIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyVAQC4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLgouLi4uLi4uLkBALT0uLi4uLi5AQEBAQEBAQCNAQCojKioj"
"IyMjIyMjIyMjIyMjIyNAQEBAQEBAIyMjI0BALi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4KLi4uLi4u"
"Li5AKj09Li4uLi4uLkAuLi4uLkBAQCMjIyMjIyNAQEBAQEBAQCojI0BAKzouLi4uJUBAIyVAQEBA"
"QEBAQEAuLi4uLi4uLi4uLi4uLi4uCi4uLi4uLi4uQEAtLT0uLi4uLi4uLi4uLi4uQEAjIyMjI0BA"
"Iy4uLi4uLitAQEBALi4uLi4uLi4uQEBALi4uLi4uLi5AQC4uLi4uLi4uLi4uLi4uLgouLi4uLi4u"
"Li4jQEA9Kz0uLi4uLi4uLi4uQEBAQEBAQEBALi4uLi4uLi4uLj0jLi4uLi4uLi4uLi5ALi4uLi4u"
"Li4uLkBALi4uLi4uLi4uLi4uLi4KLi4uLi4uLi4uLi5AQD06Li4uLi4lQEBAQCMuLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi5AQC4uLi4uLi4uLi4uLi4uCi4uLi4uLi4u"
"Li5AQD09Li4uLi4uQEBAQCsrLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4u"
"Li4qQEAuLi4uLi4uLi4uLi4uLgouLi4uLi4uLi4uJSs9PS0uLi4uK0BAQEA9LS4uLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uOi4uLi4uLi4uLi0lQC4uLi4uLi4uLi4uLi4KLi4uLi4uLi4u"
"LkBAKj0tLT09PSVALi5AJT09LS06Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi46PT06Li4uLi4u"
"Li49PUAlLi4uLi4uLi4uLi4uCi4uLi4uLi4uLi4uLkBAQEBAQEAlLi4uOkBAPT09PSouLi4uLi4u"
"Li4tLS4uLi4uLi4uLi4uLj09JSMrLT06Li4uLi4rPUBALi4uLi4uLi4uLi4uLgouLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uQEBAQCU9KzouLi4uPTo9Kz0rPT0tOjotPSs9Kz09QEBAQCs9PS0tPSot"
"LUBALi4uLi4uLi4uLi4uLi4KLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi49QCorKyVALi0rKys9PSsr"
"QEBAPT09PT09Kys9LUBAQCUqKytAQEBAQEBAQEBAOi4uLi4uLi4uLi4uLi4uCi4uLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4lQCoqKyorK0BAQCUlQEBAQCsrK0BAQCVAQEBAQEBAQEAlJSUlJSUlQEBAQEAl"
"K0AlLi4uLi4uLi4uLi4uLgouLi4uLi4uLi4uLi4uLi4uLi4uLi4tQCMqIysrKz0qKysrKyorKisr"
"KysjQEAlJT06Ojo6Ojo6Ojo6Ojo6Ojo6Ojo6OjojQEAjLi4uLi4uLi4uLi4KLi4uLi4uLi4uLi4u"
"Li4uLi4uLi4uQCMqKiorKysrKysrKysrKysqKyVAIz06Ojo6Ojo6Ojo6Li4uLi4uLi4uLi4uLi46"
"Ojo6OiNAOi4uLi4uLi4uCi4uLi4uLi4uLi4uLi4uLi4uLi4uQEAqKioqKysrKysrKyorKyorK0Aq"
"PS09Ojo6Ojo6Ojo6Li4uLi4uLi4uLi4uLi4uLi46Ojo6OipALi4uLi4uLgouLi4uLi4uLi4uLi4u"
"Li4uLi4uLkAqKioqKisrKysrKysrKysrK0A9PT09PS06Oi46Ojo6Oi4uLi4uLi4uLi4uLi4uLi4u"
"Ljo6Ojo6OkAuLi4uLi4KLi4uLi4uLi4uLi4uLi4uLi4uLi1AKiojKiorKysrKysrKysrKkBAPT09"
"PT09LTo6Ojo6Ojo6Oi4uLi4uLi4uLi4uLi4uLi46Ojo6OjoqQC4uLi4uCi4uLi4uLi4uLi4uLi4u"
"Li4uLi5AQCoqKioqKysrKysrKysrKytAPSs9PT0tPSs9Ojo6Ojo6Ojo6Ojo6Oi4uLi4uLjo6Ojo6"
"Ojo6Ojo6PSVALi4uLgouLi4uLi4uLitAQCUrKysrI0BAQCMqKioqKiorKysrKysrPSsqQD09PT09"
"PT09PT0tOjo6Ojo6Ojo6Ojo6Ojo6Ojo6Ojo6Ojo6OjotPT09QC4uLi4KLi4uLi4uLUAqPSsrKysr"
"Kys9K0AjKioqKiMqKysrKysrKisrKkBAPT09PSs9PT09PT09PS06Ojo6Ojo6Ojo6Oi46Ojo6Ojo6"
"PT09PT09PUAuLi4uCi4uLi4uPUArKysrKysrKysrKytAKioqKiojKisrKisrKysrKysrQD09PT09"
"PT09PS09PSs9LT09PS0tPT0rKz0rPSs9PT0rPT09PT09PStALi4uLgouLi4uLkAlKysrKysrKysr"
"Kys9QCoqKioqKiorKysrKysrKz0rKyVAKy09Kz09LT09PT09PT09PT09PT09PT09PT09PT09PT09"
"PT09PStAKy4uLi4KLi4uLi5AKysrKyorKyoqKiorPUAqKioqKisqKysrKysrPT0qKysrKkA9PSs9"
"PT09Kz09PT09Oj09PT09LT09PT0rPT0rPT09Kz09PStAQC4uLi4uCi4uLi4uQCsrKioqKioqKioq"
"KipAKioqKioqKiorKysrKysrKysqKysrQEA9PT09PSs9PT09PS09PT09LT0rPT09PT09Kz09PSs9"
"PUBALi4uLi4uLgouLi4uOkAqKioqIyMqKioqKiojQCoqKioqKiMqKysrKysrKisrKysrKysrJUBA"
"Kj09PT0rPSs9PT09PT09PT09KysrPT0tK0BAQEBALi4uLi4uLi4KLi4uLipAKioqKioqIyMqKioq"
"I0AjKioqKiojIysrKysrKysrKisrKysrKysrKysqQEBAQEBAQEBAIyMlQEBAQEBAJUAlPSsrKyoq"
"QC4uLi4uLi4uCi4uLi4lQCMqKioqKioqKyorKipAKioqKiojKioqKysrKysrKysrKysrKisrKysr"
"KysrKisrKysrKysrKisrKisrKysrKysrKysqI0AuLi4uLi4uLgouLi4uQEAqKioqKiojKioqKioj"
"QCoqKioqIyoqKisrKyorKysrKysrKysrKysrKysrKisrKysrKysrKysrKysrKysrKiorKysrKiNA"
"Li4uLi4uLi4KLi4uLkBAKioqKioqKiorKioqKkAjKiojKioqIyMqKyorKysrKysrKysqKysrKisr"
"KisrKysrKysrKysrKysrKysrKysrKysrKyojQC4uLi4uLi4uCi4uLi4lQCoqKioqKiorKioqIypA"
"IyoqKioqKiojIysrKysrKyorKysrKysrKysrKysrKysrKysrKysrKysrKysqKysrKysrKyoqKkAu"
"Li4uLi4uLgouLi4uI0AqKioqIyoqKioqKioqQCMqKiMqKiojKiojKisrKysrKysrKysrKyorKysr"
"KysrKisrKysrKysrKysqKisrKysrKysqIypALi4uLi4uLi4KLi4uLkBAKioqKiMqKioqKioqKiVA"
"IyMqKioqIyMjIyorKysrKysrKysrKysrKysrKysrKysqKiorKysrKysrKyoqKysrKysqKioqQC4u"
"Li4uLi4uCi4uLi5AQCoqKiMqKioqKioqKiNAQCoqKioqKiojKioqKisrKisrKysrKysrKysqKysr"
"KyoqKiorKysrKiorKyoqKysrKysqIyMqKkAuLi4uLi4uLgouLi4uJUAqKioqKiMqKisqKiMqQEAq"
"KioqKioqKioqKioqKysrKysqKysrKysrKiorKysqKysrKysqKiorKysqKisrKyoqIyoqKiNALi4u"
"Li4uLi4KLi4uLitAIyoqKioqKioqKiojKiVAIyoqKioqKioqKioqKiorKysqKiorKysrKysqKyoq"
"KysrKz09KysrKysrKysqKysqKioqKiojQC4uLi4uLi4uCi4uLi4uQCoqKyoqKioqKisqKiorQCoj"
"KioqKioqIyMqKioqKiorKysqKysrKysrKysrKyorKysrKys9KisrKysrKysqKioqKiojI0AuLi4u"
"Li4uLgouLi4uLkAjKisqKioqKioqKioqKkAqKioqKioqIyoqKioqKioqKisrKysrKysrKisrKioq"
"KysrKysrKysrKysqKiMqKioqKioqI0AlLi4uLi4uLi4KLi4uLi5AIyoqKz0qKisqKioqKipAIyoq"
"KiojKioqKioqKiojKioqKiorKysrKysrKysqKyorKysrKysrKyojKiMqKiMqIyoqIypALS4uLi4u"
"Li4uCi4uLi4uI0AjKiorKioqKioqKisqQCoqKioqKioqKioqKiMqKioqKioqKiojKioqKisrKysq"
"KysrKioqIyoqKioqKioqKioqKiMqQC4uLi4uLi4uLgouLi4uLi5AKiMqKioqKioqKioqKkAjKioj"
"KioqKioqKioqKiMqKioqKioqKioqKioqKioqIyoqKioqKiorKioqKioqKioqKioqI0AuLi4uLi4u"
"Li4KLi4uLi4uLiVAKiMqKioqKioqKipAIyMqKioqKioqKioqKioqIyoqKioqKioqKioqKiojKioq"
"KioqKioqKioqKioqKioqKioqKiVALi4uLi4uLi4uCi4uLi4uLi4uLi5AQCUjKioqKiolQEAqKioq"
"KioqKiMqKioqKiMqIyoqKioqKioqKioqKioqKioqKioqKipAJSMjKioqKiMqKipAQC4uLi4uLi4u"
"LgouLi4uLi4uLi4uLi4uLi4uLi4uLj1AIyoqKioqKioqKioqKioqKioqIyoqQCUqIyoqKioqKioq"
"JUBAQEAqKyojKioqKioqKiojQC0uLi4uLi4uLi4KLi4uLi4uLi4uLi4uLi4uLi4uLi4uQCoqKioq"
"KiMqKioqIyoqKiojKiMqK0AuLi4uLi4uLi4uQCojKioqKiojKioqKioqKioqKkAuLi4uLi4uLi4u"
"Ci4uLi4uLi4uLi4uLi4uLi4uLi4uLkAqKioqKioqKiojKioqKisqIyMqKiNALi4uLi4uLi4uLkAj"
"IyoqKiMqKioqKioqKioqIyVALi4uLi4uLi4uLgouLi4uLi4uLi4uLi4uLi4uLi4uLi5AKiorKioq"
"KioqKioqKioqKioqKiojQC4uLi4uLi4uLi5AJSoqKioqKioqKioqKioqKipAIy4uLi4uLi4uLi4K"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uQCMjKiojKiMqIyojKioqKiojKioqQEAuLi4uLi4uLi4uQCUj"
"KioqKioqKioqIyoqIyojQC4uLi4uLi4uLi4uCi4uLi4uLi4uLi4uLi4uLi4uLi4uLkAqKiojKioq"
"KiMqKiMqKioqKioqKkAlLi4uLi4uLi4uLkBAIyMqKioqKioqKioqKioqQEAuLi4uLi4uLi4uLgou"
"Li4uLi4uLi4uLi4uLi4uLi4uLi5AIyojKiojKioqKioqKioqKiojKiNAJS4uLi4uLi4uLi4qQCoq"
"KioqKiojKioqKioqKkA9Li4uLi4uLi4uLi4KLi4uLi4uLi4uLi4uLi4uLi4uLi4uQCUqKioqKioq"
"KioqKysqKioqKioqQCouLi4uLi4uLi4uOkAqKioqKioqKioqKioqKiNALi4uLi4uLi4uLi4uCi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4lQEBAQEBAQEBAQEBAQEBAQEBAQCUuLi4uLi4uLi4uLi4uPSoj"
"JSVAQEBAQEBAJSUrOi4uLi4uLi4uLi4uLgouLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4KLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uLi4u"
"Li4uLi4uLi4uLi4uLi4uLi4uLi4uLi4uCgo=";

int main() {
    cout << Decode(text);
}


static char CharToSixBit(char c) {
	char lookupTable[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
	};

	if (c == '=')
	{
		return 0;
	}
	else
	{
		for (int x = 0; x < 64; x++)
		{
			if (lookupTable[x] == c)
				return (char)x;
		}

		return 0;
	}
}

static string Decode(string data) {
	int length, length2, length3;
	int blockCount;
	int paddingCount = 0;
	int dataLength = data.length();

	length = dataLength;
	blockCount = length / 4;
	length2 = blockCount * 3;

	for (int x = 0; x < 2; x++)
	{
		if (data[length - x - 1] == '=')
			paddingCount++;
	}

	char* buffer = new char[length];
	char* buffer2 = new char[length2];

	for (int x = 0; x < length; x++)
	{
		buffer[x] = CharToSixBit(data[x]);
	}

	char b, b1, b2, b3;
	char temp1, temp2, temp3, temp4;

	for (int x = 0; x < blockCount; x++)
	{
		temp1 = buffer[x * 4];
		temp2 = buffer[x * 4 + 1];
		temp3 = buffer[x * 4 + 2];
		temp4 = buffer[x * 4 + 3];

		b = (char)(temp1 << 2);
		b1 = (char)((temp2 & 48) >> 4);
		b1 += b;

		b = (char)((temp2 & 15) << 4);
		b2 = (char)((temp3 & 60) >> 2);
		b2 += b;

		b = (char)((temp3 & 3) << 6);
		b3 = temp4;
		b3 += b;

		buffer2[x * 3] = b1;
		buffer2[x * 3 + 1] = b2;
		buffer2[x * 3 + 2] = b3;
	}

	length3 = length2 - paddingCount;
	string result;

	for (int x = 0; x < length3; x++)
	{
		result += buffer2[x];
	}

	delete[] buffer;
	delete[] buffer2;

	return result;
}
