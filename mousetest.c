#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char track[] = {
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     50,50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
     -50,-50,
};

int main(int argc, const char *argv[])
{
	const char *filename = NULL;
	int fd = 0;
	char report[8];
	int count;
	int i;

	/* filename = argv[1]; */
	filename = "/dev/android_mouse0";

	if ((fd = open(filename, O_RDWR, 0666)) == -1) {
		perror(filename);
		return 3;
	}

	count = 50;
	while (count) {

	     for(i = 0; i< sizeof(track); i = i+2 ){
		  memset(report, 0x0, sizeof(report));
		  report[1] = track[i];
		  report[2] = track[i+1];
	   
		  if (write(fd, report, 3) != 3) {
		       perror(filename);
		       return 1;
		  }
		  usleep(5000000);
	     }

	     count--;
	}
	
	close(fd);
	return 0;
}
