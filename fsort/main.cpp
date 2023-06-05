#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool sortStrI(string aaa, string bbb)
{
	return (stricmp(aaa.c_str(), bbb.c_str()) < 0);
}

int main(int argc, char **argv)
{
	//Usage: fsort [file] [fileResult]

	if(argc < 3)
	{
		printf(
			"Usage: %s %s %s\nFSort ERASES result file!!!",
			argv[0],
			argc>1?argv[1]:"<file>",
			argc>2?argv[2]:"<fileResult>");
		return 0;
	}

	char  *f1_p = argv[1]
		, *fR_p = argv[2];

	printf("DEBUG:\n%s\n%s\n", f1_p, fR_p);

	FILE  *f1 = fopen(f1_p, "r")
		, *fR = fopen(fR_p, "w+");

	printf("FILE_PTRS: %xu, %xu\n\n", f1, fR);

	assert(f1 != 0);
	assert(fR != 0);

	vector<string> concated;
	char buf[500];
	while(!feof(f1))
	{
		memset(buf, 0, 500);
		fgets(buf, 499, f1);
		char *p = strrchr(buf, '\n');
		if(p) *p = '\0';
		concated.push_back(buf);
	}
	concated.pop_back();
	sort(concated.begin(), concated.end(), sortStrI);
	fclose(f1);
	for(int i = 0; i < concated.size(); ++i)
	{
		static bool ccc = true;
		fprintf(fR, "%s%s", ccc?"":"\n", concated[i].c_str());
		ccc = false;
	}
	fclose(fR);

	return 0;
}