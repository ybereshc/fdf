#define MAX(a,b) ({typeof(a) _a = (a); typeof(b) _b = (b); _a > _b ? _a : _b;})
#define MIX(a,b) ({typeof(a) _a = (a); typeof(b) _b = (b); _a < _b ? _a : _b;})

int awd(int a)
{
	printf("www\n");
	return a;
}

#define qwe(a, b) (a > b ? a : b)

int main(int argc, char const *argv[])
{
	printf("%d\n", MAX(awd(1), awd(2)));
	return 0;
}