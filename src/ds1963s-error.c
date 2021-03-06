#include <stdio.h>
#include "ds1963s-error.h"

static char *__errors[] = {
	"Success",
	"Failed to open serial port",
	"DS2480B adapter not found",
	"Invalid address.  Valid addresses are 0..704",
	"Failed to set serial control bits",
	"Failed to change 1-Wire level",
	"DS1963S ibutton not found",
	"Invalid secret number",
	"Invalid secret length",
	"Invalid data length",
	"Access to device failed",
	"Failed to transmit data block",
	"Failed to erase scratchpad",
	"Failed to read scratchpad",
	"Data integrity error",
	"Failed to copy scratchpad",
	"Invalid page number.  Valid numbers are 0..21"
};

void ds1963s_perror(int errno, const char *s)
{
	size_t errnum = sizeof(__errors) / sizeof(char *);

	if (s && *s)
		fprintf(stderr, "%s: ", s);

	if (errno < 0 || errno >= errnum)
		fprintf(stderr, "Unknown error number.\n");
	else
		fprintf(stderr, "%s.\n", __errors[errno]);
}
