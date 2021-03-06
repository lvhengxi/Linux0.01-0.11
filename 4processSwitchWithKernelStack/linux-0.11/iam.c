#define __LIBRARY__
#include <unistd.h>
#include <errno.h>


_syscall1(int, iam, const char*, name)

#define NAMELEN 100
char name[NAMELEN];

int main(int argc, char *argv[])
{
	int res;
	int namelen = 0;
	if (2 == argc) {
		while ((name[namelen] = argv[1][namelen]) != '\0')
			namelen++;
		res = iam(name);
		if(res<0)
			errno = EINVAL;
		return res;
	}
}
