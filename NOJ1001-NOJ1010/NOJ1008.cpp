#include<stdio.h>

using namespace std;

int md[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year)  {
	return !(year % 4) && (year % 100) || !(year % 400);
}

int size_of_year(int year) {
	return is_leap_year(year) ? 366 : 365;
}

int day_of_feb(int year) {
	return is_leap_year(year) ? 29 : 28;
}

int main() {

	int year, month, day;
	int diff = 0;
	int count = 0;

	while (1) {

		scanf("%d", &year);
		if (year == -1) break;
		scanf("%d%d", &month, &day);

		for (int i = 2000; i < year; i++) {
			diff += size_of_year(i);
		}

		md[2] = day_of_feb(year);
		for (int j = 1; j < month; j++) {
			count += md[j];
		}
		count += day;
		diff +=count-1;

		printf("%d\n%d\n", diff, count);
		diff = 0;
		count = 0;

	}

}