#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	//Usage: concat [file1] [file2] [fileResult] [concatMode]
	//concatMode: concat - only concat files
	//            concat2 - concat and then DELETE repeating strings (for lists)

	if(argc < 5)
	{
		printf(
			"Usage: %s %s %s %s %s\nConcat APPENDS TO END in result file!!!",
			argv[0],
			argc>1?argv[1]:"<file1>",
			argc>2?argv[2]:"<file2>",
			argc>3?argv[3]:"<fileResult>",
			argc>4?argv[4]:"<concat|concat2>");
		return 0;
	}

	char  *f1_p = argv[1]
		, *f2_p = argv[2]
		, *fR_p = argv[3];
	bool ccmode1 = (0 == strcmp("concat", argv[4]));
	bool ccmode2 = (0 == strcmp("concat2", argv[4]));
	if(!ccmode1 && !ccmode2) ccmode1 = true;

	printf("DEBUG:\n%s\n%s\n%s\n%i\n%i\n", f1_p, f2_p, fR_p, ccmode1, ccmode2);

	FILE  *f1 = fopen(f1_p, "r")
		, *f2 = fopen(f2_p, "r")
		, *fR = fopen(fR_p, "r+");

	printf("FILE_PTRS: %xu, %xu, %xu\n\n", f1, f2, fR);

	assert(f1 != 0);
	assert(f2 != 0);
	assert(fR != 0);

	vector<string> concated;
	char buf[500];
	while(!feof(fR))
	{
		memset(buf, 0, 500);
		fgets(buf, 499, fR);
		char *p = strrchr(buf, '\n');
		if(p) *p = '\0';
		if(    (ccmode2 && concated.end() == find(concated.begin(), concated.end(), buf))
			|| (ccmode1))
			concated.push_back(buf);
	}
	while(!feof(f1))
	{
		memset(buf, 0, 500);
		fgets(buf, 499, f1);
		char *p = strrchr(buf, '\n');
		if(p) *p = '\0';
		if(    (ccmode2 && concated.end() == find(concated.begin(), concated.end(), buf))
			|| (ccmode1))
			concated.push_back(buf);
	}
	concated.pop_back();
	while(!feof(f2))
	{
		memset(buf, 0, 500);
		fgets(buf, 499, f2);
		char *p = strrchr(buf, '\n');
		if(p) *p = '\0';
		if(    (ccmode2 && concated.end() == find(concated.begin(), concated.end(), buf))
			|| (ccmode1))
			concated.push_back(buf);
	}
	concated.pop_back();
	fclose(f1);
	fclose(f2);
	freopen(fR_p, "w+", fR);
	for(int i = 0; i < concated.size(); ++i)
	{
		static bool ccc = true;
		fprintf(fR, "%s%s", ccc?"":"\n", concated[i].c_str());
		ccc = false;
	}
	fclose(fR);

	return 0;
}