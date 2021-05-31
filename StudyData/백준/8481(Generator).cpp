#ifndef _GLIBCXX_NO_ASSERT 
#include <cassert> 
#endif #include <cctype>
#include <cerrno> 
#include <cfloat> 
#include <ciso646> 
#include <climits> 
#include <clocale> 
#include <cmath> 
#include <csetjmp> 
#include <csignal>
#include <cstdarg> 
#include <cstddef>
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#if __cplusplus >= 201103L 
#include <ccomplex> 
#include <cfenv> 
#include <cinttypes> 
#include <cstdalign> 
#include <cstdbool>
#include <cstdint> 
#include <ctgmath>
#include <cwchar> 
#include <cwctype>
#endif 
//
//// C++ 
#include <algorithm> 
#include <bitset> 
#include <complex> 
#include <deque> 
#include <exception> 
#include <fstream> 
#include <functional> 
#include <iomanip> 
#include <ios> 
#include <iosfwd> 
#include <iostream> 
#include <istream> 
#include <iterator> 
#include <limits> 
#include <list> 
#include <locale> 
#include <map> 
#include <memory> 
#include <new> 
#include <numeric>
#include <ostream> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <stdexcept> 
#include <streambuf> 
#include <string> 
#include <typeinfo> 
#include <utility> 
#include <valarray> 
#include <vector> 
//
#if __cplusplus >= 201103L 
#include <array> 
#include <atomic> 
#include <chrono> 
#include <condition_variable> 
#include <forward_list> 
#include <future> 
#include <initializer_list> 
#include <mutex> 
#include <random> 
#include <ratio>
#include <regex> 
#include <scoped_allocator> 
#include <system_error> 
#include <thread> 
#include <tuple> 
#include <typeindex> 
#include <type_traits> 
#include <unordered_map> 
#include <unordered_set> 
#endif

#pragma warning(disable:4996)

using namespace std;


#define endl "\n"
#define int long long
#define float double
#define Debug(a,b) cout << a << " " << b << endl

int Mul(int x, int y, int mod)
{
	return x * y % mod;
}

int GCD(int a, int b)
{
	if (a < b)
		swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return (int)n + 1;
	else
		return n;
}

int Pow(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a);
		b = b >> 1;
		a = (a * a);
	}
	return res;
}
int Pow(int a, int b, int p)
{
	int res = 1;
	a = a % p;
	while (b > 0)
	{
		if (b & 1)
			res = Mul(res, a, p);
		b = b >> 1;
		a = Mul(a, a, p);
	}
	return res;
}

const int INF = 8999999999999999999;

////////////////////////////////////////////////////////////////////////

using namespace std;

//ofstream ofile;
//ofile.open("output.txt");
//for (int x = 0; x < 10; x++)
//	ofile << x << endl;
//ofile.close();
// 
//ifstream file("gen1.txt");
//stringstream ss;
//ss << file.rdbuf();
//string ansString = ss.str();

void Fun0()
{
	cout << "ONTAK 2010" << endl;
}
void Fun1()
{
	string Fun1String = "Godzila terorizes Bajtoly lower again. Every day a monster comes out of the ocean, slow movement of marching through the city to some of the skyscrapers and eats it with people who are in it. Eating one skyscraper takes the whole day, at dusk, it returns to its hiding place hiden in the depths. To make maters worse, going through the city, Godzila wags its tail and destroys towers, near the pases. The prospect of becoming a meal for an underwater monster, to discourage some residents spent in uncomfort- tion in the city. During the night of each tower is derived as a resident and fles to the countryside. In Bajtogrodzie skyscrapers were built only at stret crosings. At each intersection there is exactly one building. Junctions are conected by two-way strets. In adition, a the junction is just above the ocean, this is where Godzila begins its destructive journey through the city. During the investigation, the monster moves only in the strets. Godzila noted that he must hury up with the consumption of residents and carefuly chose the skyscrapers devouring and strets, which reaches them. Of course, chosing never previously consumed or destroyed- wanego skyscraper. What is the maximum number of people who can eat before the city completely desolate? Entrance The first line of standard input contains two integers him (1 n 10 0, 0 50 0 m) respectively denoting the number of intersections in the city and the number of conecting strets. Crosroads numbers are numbered from 1 to n, junction 1 is located on the shores of the ocean. Next row contains a sequence of integers n s (0 s 10 0) to describe population skyscrapers at various intersections. In each of the next m rows are the two integers ai and bi (1 ai, bi n, ai = bi), which means that there is a road junction conecting ai and bi. The crosing number One can reach any other intersection in the city. Exit Write to stdout the number of people who eat Godzila for the optimum choice of meals and roads through the city every day. Example For input: the result is corect: 5 5 1 1 3 2 4 7 1 2 1 3 2 3 2 4 3 5";
	int AddArr[2081] = { 0,0,0,0,0,2896,-13,-15,-17,-19,2767,-48,-52,-56,-60,-64,-68,-72,-76,-80,-84,-88,-92,-96,-100,-104,-108,-112,-116,-120,-124,-128,-132,-136,-140,-144,-148,-152,-156,-160,-164,-168,-172,-176,-180,-184,-188,-192,-196,-200,-204,-208,-212,2716,2712,-224,-228,-232,-236,-240,-244,-248,-252,-256,-260,-264,-268,-272,-276,-280,-284,-288,-292,-296,-300,2628,2624,-312,-316,-320,-324,-328,-332,-336,-340,-344,-348,-352,-356,-360,-364,-368,2560,2556,-380,-384,-388,-392,-396,-400,-404,-408,-412,-416,-420,-424,-428,2500,2496,-440,-444,-448,-452,-456,-460,-464,-468,-472,-476,-480,2448,2444,-492,-496,-500,-504,-508,-512,-516,-520,-524,2404,2400,-536,-540,-544,-548,-552,-556,-560,-564,-568,2360,2356,-580,-584,-588,-592,-596,-600,-604,-608,2320,2316,-620,-624,-628,-632,-636,-640,-644,2284,2280,-656,-660,-664,-668,-672,-676,-680,2248,2244,-692,-696,-700,-704,-708,-712,2216,2212,-724,-728,-732,-736,-740,-744,2184,2180,-756,-760,-764,-768,-772,-776,2152,2148,-788,-792,-796,-800,-804,2124,2120,-816,-820,-824,-828,-832,2096,2092,-844,-848,-852,-856,-860,2068,2064,-872,-876,-880,-884,-888,2040,2036,-900,-904,-908,-912,2016,2012,-924,-928,-932,-936,-940,1988,1984,-952,-956,-960,-964,1964,1960,-976,-980,-984,-988,1940,1936,-1000,-1004,-1008,1920,1916,-1020,-1024,-1028,-1032,1896,1892,-1044,-1048,-1052,-1056,1872,1868,-1068,-1072,-1076,1852,1848,-1088,-1092,-1096,-1100,1828,1824,-348,-1677,1249,1243,1237,-1701,-1707,1219,1213,1207,-1731,-1737,1189,1183,1177,-1761,-1767,1159,1153,1147,-1791,-1797,1129,1123,1117,-1821,-1827,1099,1093,1743,-2472,452,444,436,428,420,412,404,396,-2544,380,372,364,356,348,340,332,324,-2616,308,300,292,284,276,268,260,252,-2688,236,228,220,212,204,196,188,180,172,164,156,148,2312,-573,-583,-593,-603,-613,-623,-633,2289,-653,-663,-673,2249,-693,-703,-713,2209,-733,-743,-753,2169,-773,-783,-793,2129,-813,-823,-833,2089,-853,-863,2059,2049,-893,-903,2019,-923,-933,-943,1979,-963,-973,-983,1939,-1003,-1013,1909,1899,-1043,1535,1064,-1880,-1892,1028,1016,-1928,992,980,968,-1976,944,932,-2012,908,896,884,-2060,860,848,-2096,824,812,800,-2144,776,764,-2180,740,728,716,-2228,692,680,-2264,656,644,632,620,608,596,-2348,572,560,-2384,536,524,512,500,488,476,-2468,452,440,-2504,416,404,392,380,368,356,344,332,320,308,296,284,272,260,248,-2696,224,212,-2732,188,176,164,152,140,128,116,104,92,80,68,56,44,32,20,8,-4,-16,-28,-40,-52,-64,-76,-88,-100,-112,-124,-136,-148,-160,-172,-184,2736,-208,-220,2700,-244,-256,-268,-280,-292,-304,-316,-328,-340,-352,-364,-376,-388,2532,-412,-424,2496,-448,-460,-472,-484,-496,-508,-520,-532,-544,-556,2364,-580,-592,2328,-616,-628,-640,-652,2268,-676,-688,2232,-712,-724,-736,-748,2172,-772,-784,2136,-808,-820,-832,-844,2076,-868,-880,2040,-904,2016,-928,-940,1980,-964,-976,-988,-1000,1920,-1024,-1036,1884,-1060,1860,-1084,-1096,1824,-1120,1800,-1144,-1156,1764,-1180,1740,-1204,-1216,1704,1248,487,-2459,459,445,431,417,403,389,375,361,347,333,319,-2627,291,277,263,249,-2697,221,207,193,179,165,151,137,123,109,95,81,67,53,39,25,11,-3,-17,-31,-45,-59,-73,-87,-101,-115,-129,-143,2775,-171,-185,-199,-213,-227,-241,-255,-269,-283,-297,-311,-325,-339,-353,-367,2551,-395,2523,-423,-437,-451,-465,-479,-493,-507,2107,1056,1040,1024,-1924,992,39,-395,-413,-431,-449,-467,2447,-503,2411,-539,-557,-575,-593,-611,-629,-647,-665,-683,-701,2213,-737,2177,-773,2141,-809,2105,-845,2069,-881,-899,-917,-935,-953,-971,-989,-1007,-1025,-1043,1871,-1079,1835,-1115,1799,-1151,1763,-1187,1727,-1223,1691,-1259,1655,-1295,1619,-1331,1583,-1367,1547,-1403,1511,-1439,1475,-1475,1439,-1511,1403,-1547,1367,-1583,1331,-1619,1295,-1655,1259,-1691,1223,72,-320,-340,-360,-380,-400,-420,-440,-460,2452,-500,2412,-540,2372,-580,2332,-620,2292,-660,-680,-700,-285,641,-2313,597,-2357,553,531,509,487,2892,-1128,1780,-1176,1732,-1224,1684,-1272,-1296,1612,-1344,1564,-1392,1516,-1440,1468,-1488,1420,-1536,1372,1348,-1608,1300,-1656,1252,-1704,1204,-1752,1156,-1800,1108,1084,-1872,1036,-1920,988,-1968,940,916,892,868,844,820,-2136,772,-2184,724,700,676,652,-2304,604,-2352,556,532,508,484,460,436,-2520,388,364,340,316,292,268,-2688,2679,-1511,1395,-1563,1343,1317,-1641,1265,-1693,1213,1187,1161,1135,-1823,1083,-1875,1031,1005,-1953,953,-2005,901,875,-2083,823,-2135,771,745,719,693,-2265,641,615,589,563,-2395,511,485,459,433,-2525,381,355,329,303,277,251,225,199,173,147,121,95,69,43,17,-9,-35,-61,-87,-113,-139,-165,-191,-217,-243,2663,-295,-321,-347,-373,-399,-425,-451,2455,-503,-529,-555,-581,-607,-633,-659,2247,-711,-737,2169,-789,-815,2091,-867,2039,-919,-945,1961,-997,-1023,1883,-1075,-1101,1805,-1153,-1179,1727,-1231,1675,1649,-1309,1597,-1361,-1387,1519,-288,-464,-492,-520,-548,-576,-604,-632,-660,-688,2540,235,205,175,145,115,85,55,25,-5,-35,-65,-95,-125,-155,-185,-215,-245,-275,-305,-335,2567,-395,-425,3220,444,412,380,348,316,284,252,220,188,156,124,-2840,60,28,-4,-36,-68,-100,-132,-164,-196,-228,-260,-292,2608,-356,-388,2512,-452,-484,-516,-548,-580,-612,2288,-676,-708,2192,-772,-804,-836,2064,-900,-932,1968,-996,-1028,1872,1840,468,-329,-363,-397,-431,3127,316,280,-2688,208,172,136,100,64,28,-8,-44,-80,-116,-152,-188,-224,-260,-296,-332,-368,2528,-440,-476,-512,2384,-584,-620,-656,-692,-728,-764,2132,-836,-872,-908,1988,-76,-277,-315,-353,-391,-429,-467,-505,-543,-581,2313,-657,-695,-733,2161,-809,-847,-885,2009,1971,-999,-1037,1857,1819,-1151,-1189,1705,1667,-1303,-1341,1553,1515,-1455,-1493,1401,1363,1325,-1645,172,1872,-1100,-1140,-1180,1712,1672,-1300,-1340,1552,1512,-1460,-1500,1392,1352,1312,-1660,-1700,1192,1152,-1820,-1860,1032,992,952,-2020,-2060,832,792,752,-2220,672,632,592,552,-2420,472,432,392,352,312,272,232,192,152,112,72,32,-8,-48,-88,-128,-168,-208,-248,-288,-328,-368,-408,-448,2444,-528,-568,-608,-648,2244,-728,-768,-808,-848,2044,2004,-968,-1008,-1048,1844,1804,1764,-1208,-1248,-1288,1604,1564,-1408,-1448,-1488,1404,1364,1324,-1648,-1688,-1728,1164,1124,1084,-1888,-1928,-1968,924,884,844,804,-2168,724,684,644,604,564,-2408,484,444,404,364,324,284,244,204,164,124,84,44,4,-36,-76,-116,-156,-196,-236,2656,-316,-356,-396,-436,-476,-516,2376,-596,-636,-676,-716,-756,-796,2096,2056,-916,-956,-996,-1036,-1076,1816,1776,1736,-1236,-1276,-1316,-1356,1536,1496,1456,1416,-1556,-1596,-1636,-1676,1216,1176,1136,1096,1056,-1916,-1956,-1996,896,856,816,776,736,696,-2276,-2316,576,536,496,456,416,376,336,296,-2676,216,176,136,96,56,16,-24,-64,-104,2788,-184,-224,-264,-304,-344,-384,-424,-464,-504,2388,2348,-624,-664,-704,-744,-784,-824,-864,-904,-944,1948,1908,1868,1828,-1144,-1184,-521,-1055,1754,-735,-781,2105,2059,2013,4859,-824,339,-560,-612,-664,-716,-768,-820,-872,2008,1956,1904,1852,1800,1748,-1236,-1288,-1340,-1392,-1444,-1496,-1548,-1600,-1652,1228,1176,1124,1072,1020,968,916,864,812,760,708,656,604,-2380,-2432,-2484,-2536,344,292,240,188,136,84,32,-20,-72,-124,-176,-228,-280,-332,-384,-436,-488,-540,-592,-644,-696,-748,2132,2080,2028,1976,1924,1872,1820,1768,1716,1664,1612,1560,1508,1456,1404,1352,1300,1248,1196,1144,1092,1040,988,936,884,3760,783,729,675,621,567,513,459,405,351,297,3075,168,112,56,0,-56,-112,-168,2347,-319,-377,-435,-493,-551,-609,-667,-725,-783,-841,-899,-957,-1015,-1073,-1131,-1189,-1247,-1305,-1363,-1421,-1479,-1537,-1595,-1653,-1711,-1769,-1827,-1885,-1943,-2001,-2059,-2117,-2175,-2233,-2291,583,525,467,409,351,293,235,177,119,61,3,-55,-113,-171,-229,-287,-345,-403,-461,-519,-577,-635,2239,2181,2123,2065,2007,1949,1891,-1099,-1157,-1215,-1273,-1331,-1389,-1447,-1505,-1563,-1621,1253,1195,1137,1079,1021,963,905,847,789,731,673,615,-2375,-2433,-2491,383,325,267,209,151,93,35,-23,-81,-139,-197,-255,-313,2561,-429,-487,-545,-603,-661,-719,-777,-835,-893,-951,1923,1865,1807,1749,1691,-1299,-1357,-1415,-1473,-1531,-1589,1285,1227,1169,1111,1053,995,937,-2053,-2111,-2169,705,647,589,531,473,415,357,443,-84,3715,-868,-932,-996,-1060,-1124,1744,1680,1616,1552,-1444,-1508,-1572,-1636,1232,1168,1104,1040,976,912,-2084,-2148,720,656,592,528,464,400,336,-2660,208,144,80,16,-48,-112,-176,2692,-304,-368,-432,-496,-560,-624,2244,2180,-816,-880,-944,-1008,-1072,1796,1732,1668,-1328,-1392,-1456,-1520,1348,1284,1220,1156,-1840,-1904,964,900,836,772,708,-2288,-2352,516,452,388,324,260,-2736,132,68,4,-60,-124,-188,-252,-316,-380,-444,-508,2360,2296,-700,-764,-828,-892,1976,1912,-1084,-1148,-1212,-1276,1592,1528,1464,-1532,-1596,1272,1208,1144,1080,-1916,-1980,888,824,760,696,-2300,568,504,440,376,-2620,248,184,120,56,-8,-72,-136,-200,-264,-328,2540,-456,-520,-584,-648,2220,-776,-840,-904,-968,1900,1836,-1160,-1224,-1288,1580,1516,-1480,-1544,1324,1260,1196,-1800,-1864,1004,940,876,-2120,748,684,620,556,-2440,428,364,300,236,172,108,44,-20,-84,-148,-212,-276,-340,2528,-468,-532,-596,2272,-724,-788,-852,2016,1952,-1044,-1108,1100,983,-2015,-2081,785,719,653,-2345,521,455,389,-2609,257,191,125,59,-7,-73,-139,-205,-271,-337,-403,-469,-535,-601,2176,1432,-1568,-1636,1228,1160,1092,-1908,956,888,820,-2180,684,616,548,480,412,344,276,208,140,72,4,-64,-132,-200,2664,-336,-404,-472,2392,-608,-676,2188,-812,-880,-948,1916,-1084,-1152,1712,1644,-1356,-1424,1440,1372,-1628,1236,1168,-1832,-1900,964,896,-2104,760,692,624,556,488,420,-2580,284,216,148,80,12,-56,-124,-192,-260,-328,-396,-464,-532,-600,-668,-736,2128,-872,-940,1924,-1076,-1144,1720,1652,-1348,1516,1448,-1552,-1620,1244,-1756,-1824,1040,972,-2028,836,768,-2232,632,564,-2436,428,360,292,224,156,88,20,-48,-116,-184,-252,-320,-388,-456,-524,559,-1663,1199,-1803,-1873,989,919,849,779,709,639,569,499,429,359,289,219,149,79,9,-61,-131,-201,-271,2591,-411,-481,2381,-621,-691,2171,-831,-901,1961,-1041,-1111,1751,-1251,1611,1541,-1461,1401,-1601,-1671,1191,-1811,1051,981,-2021,841,771,-2231,631,561,491,421,351,281,211,-2791,71,1,-69,-139,-209,-279,-349,2513,-489,-559,2303,-699,-769,-839,-909,1953,-1049,-1119,1743,-1259,1603,-1399,-1469,1393,-1609,1253,1183,-1819,1043,-1959,903,833,-2169,693,623,553,483,-2519,343,273,203,133,63,-7,-77,-147,-217,2645,-93,1284,-1720,1140,1068,-1936,924,-2080,780,708,2019,-679,-753,-827,2031,-975,1883,-1123,-1197,1661,-1345,1513,-1493,1365,1291,-1715,1143,-1863,995,-2011,847,773,699,625,-2381,477,403,329,255,181,107 };
	string res = "";
	for (int i = 0; i < Fun1String.size(); i++)
		for (int j = 0; j < (2932 - (i * i) % 2932) + AddArr[i]; j++)
			res += Fun1String[i];
	cout << res << endl;
}
void Fun2()
{
	unsigned long long a = 0;
	unsigned long long b = 1;
	unsigned long long m = 9099099909999099999;

	string res = "";
	for (int x = 0; x < 10000; x++)
	{
		res += to_string(b);
		res += ", ";
		unsigned long long c = (a + b)%m;
		a = b;
		b = c;
	}
	res += "0.";

	cout << res << endl;
}
void Fun3()
{
	string res = "";
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 1024 - i; j++)
		{
			if ((i == 506 && j == 450) || (i == 506 && j == 451) || (i == 506 && j == 452) || (i == 506 && j == 453) || (i == 506 && j == 456) || (i == 506 && j == 457) || (i == 506 && j == 460) || (i == 506 && j == 461) || (i == 506 && j == 463) || (i == 506 && j == 464) || (i == 506 && j == 465) || (i == 506 && j == 466) || (i == 506 && j == 467) || (i == 506 && j == 468) || (i == 506 && j == 471) || (i == 506 && j == 472) || (i == 506 && j == 476) || (i == 506 && j == 477) || (i == 506 && j == 480) || (i == 506 && j == 481) || (i == 506 && j == 487) || (i == 506 && j == 488) || (i == 506 && j == 489) || (i == 506 && j == 490) || (i == 506 && j == 494) || (i == 506 && j == 495) || (i == 506 && j == 496) || (i == 506 && j == 497) || (i == 506 && j == 500) || (i == 506 && j == 501) || (i == 506 && j == 502) || (i == 506 && j == 505) || (i == 506 && j == 506) || (i == 506 && j == 507) || (i == 506 && j == 508) || (i == 507 && j == 449) || (i == 507 && j == 450) || (i == 507 && j == 453) || (i == 507 && j == 454) || (i == 507 && j == 456) || (i == 507 && j == 457) || (i == 507 && j == 458) || (i == 507 && j == 460) || (i == 507 && j == 461) || (i == 507 && j == 465) || (i == 507 && j == 466) || (i == 507 && j == 470) || (i == 507 && j == 471) || (i == 507 && j == 472) || (i == 507 && j == 473) || (i == 507 && j == 476) || (i == 507 && j == 477) || (i == 507 && j == 479) || (i == 507 && j == 480) || (i == 507 && j == 486) || (i == 507 && j == 487) || (i == 507 && j == 490) || (i == 507 && j == 491) || (i == 507 && j == 493) || (i == 507 && j == 494) || (i == 507 && j == 497) || (i == 507 && j == 498) || (i == 507 && j == 501) || (i == 507 && j == 502) || (i == 507 && j == 504) || (i == 507 && j == 505) || (i == 507 && j == 508) || (i == 507 && j == 509) || (i == 508 && j == 449) || (i == 508 && j == 450) || (i == 508 && j == 453) || (i == 508 && j == 454) || (i == 508 && j == 456) || (i == 508 && j == 457) || (i == 508 && j == 459) || (i == 508 && j == 460) || (i == 508 && j == 461) || (i == 508 && j == 465) || (i == 508 && j == 466) || (i == 508 && j == 469) || (i == 508 && j == 470) || (i == 508 && j == 473) || (i == 508 && j == 474) || (i == 508 && j == 476) || (i == 508 && j == 477) || (i == 508 && j == 478) || (i == 508 && j == 479) || (i == 508 && j == 489) || (i == 508 && j == 490) || (i == 508 && j == 493) || (i == 508 && j == 494) || (i == 508 && j == 497) || (i == 508 && j == 498) || (i == 508 && j == 501) || (i == 508 && j == 502) || (i == 508 && j == 504) || (i == 508 && j == 505) || (i == 508 && j == 508) || (i == 508 && j == 509) || (i == 509 && j == 449) || (i == 509 && j == 450) || (i == 509 && j == 453) || (i == 509 && j == 454) || (i == 509 && j == 456) || (i == 509 && j == 457) || (i == 509 && j == 460) || (i == 509 && j == 461) || (i == 509 && j == 465) || (i == 509 && j == 466) || (i == 509 && j == 469) || (i == 509 && j == 470) || (i == 509 && j == 471) || (i == 509 && j == 472) || (i == 509 && j == 473) || (i == 509 && j == 474) || (i == 509 && j == 476) || (i == 509 && j == 477) || (i == 509 && j == 479) || (i == 509 && j == 480) || (i == 509 && j == 487) || (i == 509 && j == 488) || (i == 509 && j == 493) || (i == 509 && j == 494) || (i == 509 && j == 497) || (i == 509 && j == 498) || (i == 509 && j == 501) || (i == 509 && j == 502) || (i == 509 && j == 504) || (i == 509 && j == 505) || (i == 509 && j == 508) || (i == 509 && j == 509) || (i == 510 && j == 450) || (i == 510 && j == 451) || (i == 510 && j == 452) || (i == 510 && j == 453) || (i == 510 && j == 456) || (i == 510 && j == 457) || (i == 510 && j == 460) || (i == 510 && j == 461) || (i == 510 && j == 465) || (i == 510 && j == 466) || (i == 510 && j == 469) || (i == 510 && j == 470) || (i == 510 && j == 473) || (i == 510 && j == 474) || (i == 510 && j == 476) || (i == 510 && j == 477) || (i == 510 && j == 480) || (i == 510 && j == 481) || (i == 510 && j == 486) || (i == 510 && j == 487) || (i == 510 && j == 488) || (i == 510 && j == 489) || (i == 510 && j == 490) || (i == 510 && j == 491) || (i == 510 && j == 494) || (i == 510 && j == 495) || (i == 510 && j == 496) || (i == 510 && j == 497) || (i == 510 && j == 501) || (i == 510 && j == 502) || (i == 510 && j == 505) || (i == 510 && j == 506) || (i == 510 && j == 507) || (i == 510 && j == 508))
				res += "#";
			else if(i&j)
				res += ".";
			else
				res += "#";
		}
		res += "\n";
	}
	cout << res;
}
void Fun4()
{
	ifstream file("gen4.txt");
	stringstream ss;
	ss << file.rdbuf();
	string ansString = ss.str();

	string check = "";
	vector<int> Arr(405003);
	for (int i = 2; i <= 400001; i++)
	{
		int flag = 0;
		for (int j = 2; j * j <= i; j++)
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		Arr[i] = flag;
	}
	int b = 0;
	for (int i = 2; i <= 400001; i++)
	{
		check += (Arr[i] + '0');
		b++;
		if (b == 80)
		{
			b = 0;
			check += "\n";
		}
	}
	string p = "909909990999999999";
	for (int i = 0,j = 0; i <= 17; i++,j++)
	{
		check[j + 269981] = p[i] ;
		if (j + 269981 == 269993)
			j++;
	}
	cout << check << endl;
}
string NumP(int n)
{
	string temp = "";
	string NumArr[] = { "","pierwszy","drugi","trzeci","czwarty","piaty","szosty","siodmy","osmy","dziewiaty","dziesiaty","jedenasty","dwunasty","trzynasty","czternasty","pietnasty","szesnasty","siedemnasty","osiemnasty","dziewietnasty" };
	string NumArr2[] = { "","","dwudziesty","trzydziesty","czterdziesty","piecdziesiaty","szescdziesiaty","siedemdziesiaty","osiemdziesiaty","dziewiecdziesiaty" };

	if (n <= 19)
		temp += NumArr[n];
	else if (20 <= n && n <= 99)
	{
		int a = n / 10;
		int b = n % 10;
		temp += NumArr2[a];
		if (b != 0)
		{
			temp += " ";
			temp += NumP(b);
		}
	}
	else if (n == 100)
		temp += "setny";
	else if (101 <= n && n <= 199)
	{
		temp += "sto ";
		temp += NumP(n%100);
	}
	else if (n == 200)
		temp += "dwusetny";
	else if (201 <= n && n <= 299)
	{
		temp += "dwiescie ";
		temp += NumP(n % 100);
	}
	else if (n == 300)
		temp += "trzysetny";
	else if (301 <= n && n <= 399)
	{
		temp += "trzysta ";
		temp += NumP(n % 100);
	}

	return temp;
}
void Fun5()
{
	string res = "";
	int Month[] = { 0,31,28,31,30, 31,30, 31,31, 30,31, 30,31 };
	string MonthP[] = { "stycznia","lutego","marca","kwietnia","maja", "czerwca","lipca", "sierpnia","wrzesnia", "pazdziernika","listopada", "grudnia" };
	string YearP[] = { "dwutysiecznego","pierwszego","drugiego","trzeciego","czwartego","piatego","szostego","siodmego","osmego","dziewiatego","dziesiatego","jedenastego","dwunastego","trzynastego","czternastego","pietnastego","szesnastego","siedemnastego","osiemnastego","dziewietnastego","dwudziestego"};
	for (int yyyy = 2000; yyyy <= 2020; yyyy++)
	{
		int dddd = 1;
		for (int mm = 1; mm <= 12; mm++)
		{
			int MonthDay = Month[mm];
			if (yyyy % 4 == 0 && mm == 2)
				MonthDay++;
			for (int dd = 1; dd <= MonthDay; dd++, dddd++)
			{
				string ddS = NumP(dd);
				ddS[0] = (char)(ddS[0] - 'a' + 'A');

				string printData = "";
		
				printData += ddS;
				printData += " ";
				printData += MonthP[mm - 1];
				printData += " to ";
				printData += NumP(dddd);
				printData += " dzien roku ";
				if(yyyy != 2000)
					printData += "dwa tysiace ";
				printData += YearP[yyyy - 2000];
				printData += ".\n";

				if (yyyy == 2007 && mm == 4 && dd == 1)
					printData = "Pierwszego kwietnia jest prima aprilis.\n";
				else if (yyyy == 2013 && mm == 6 && dd == 1)
					printData = "Pierwszego czerwca jest dzien dziecka.\n"; 
				res += printData;
			}
		}
	}
	res += "Koniec.";

	cout << res << endl;
}
long long fac[21];
string MakePer(int N,int k)
{
	vector<bool> check(21,false);
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (check[j])
				continue;
			if (k > fac[N - i - 1])
				k -= fac[N - i - 1];
			else
			{
				vec[i] = j;
				check[j] = true;
				break;
			}
		}
	string res = "";
	for (int i = 0; i < N; i++)
		res += (char)(vec[i] + 'a');
	return res;
}
void Fun6()
{	
	string res = "";
	fac[0] = 1;
	for (int i = 1; i < 21; i++)
		fac[i] = i * fac[i - 1];
	for (int i = 1; i <= 20000; i++)
	{
		string temp = "";
		if (i == 10000)
			temp += "T[10000000000000000]=\"9099099909999099999\"";
		else
		{
			int a = 1;
			int b = i * i * i * i;
			while (b >= fac[a])
			{
				b -= fac[a];
				if (b > 0)
					a++;
			}
			temp += "T[";
			temp += to_string(i * i * i * i);
			temp += "]=\"";
			temp += MakePer(a, b);
			temp += "\"";
		}
		temp += "\n";
		res += temp;
	}

	cout << res;
}
string SNum[4][200];
string AddBigNum(string N1, string N2)
{
	int maxLen = max(N1.length(), N2.length()) + 1;
	reverse(N1.begin(), N1.end());
	while (N1.length() < maxLen)
		N1 += "0";
	reverse(N1.begin(), N1.end());
	reverse(N2.begin(), N2.end());
	while (N2.length() < maxLen)
		N2 += "0";
	reverse(N2.begin(), N2.end());
	vector<int> temp(maxLen);
	for (int i = maxLen - 1; i >= 1; i--)
	{
		int a = (int)(N1[i] - '0');
		int b = (int)(N2[i] - '0');
		int ab = a + b;
		temp[i] += ab;
		int c = temp[i] / 10;
		temp[i] -= c * 10;
		temp[i - 1] += c;
	}
	string res = "";
	bool flagZ = true;
	for (int i = 0; i < temp.size(); i++)
	{
		if (flagZ && temp[i] == 0)
			continue;
		if (temp[i] != 0)
			flagZ = false;
		res += (temp[i] + '0');
	}
	return res;
}
string SubBigNum(string N1, string N2)
{
	int maxLen = max(N1.length(), N2.length()) + 1;
	reverse(N1.begin(), N1.end());
	while (N1.length() < maxLen)
		N1 += "0";
	reverse(N1.begin(), N1.end());
	reverse(N2.begin(), N2.end());
	while (N2.length() < maxLen)
		N2 += "0";
	reverse(N2.begin(), N2.end());
	vector<int> temp(maxLen);
	for (int i = maxLen - 1; i >= 1; i--)
	{
		int a = (int)(N1[i] - '0');
		int b = (int)(N2[i] - '0');
		int ab = a - b;
		if (ab < 0)
		{
			ab += 10;
			N1[i] = ab + '0';
			temp[i - 1]++;
			for (int j = i - 1; j >= 0; j--)
				if (N1[j] == '0' && temp[j] > 0)
				{
					temp[j]--;
					N1[j] = '9';
					temp[j - 1]++;
				}
				else if (N1[j] != '0' && temp[j] > 0)
				{
					temp[j]--;
					int c = N1[j] - '0';
					N1[j] = (c - 1 + '0');
				}
		}
		else
			N1[i] = ab + '0';
		
	}
	string res = "";
	bool flagZ = true;
	for (int i = 0; i < N1.size(); i++)
	{
		if (flagZ && N1[i] == '0')
			continue;
		if (N1[i] != '0')
			flagZ = false;
		res += N1[i];
	}
	return res;
}
int CmpBigNum(string N2, string N1)
{
	if (N1.size() < N2.size())
		return 1;
	else if (N1.size() > N2.size())
		return -1;
	else
	{
		for (int i = 0; i < N1.size(); i++)
		{
			int a = N1[i] - '0';
			int b = N2[i] - '0';
			if(a < b)
				return 1;
			else if (a > b)
				return -1;
		}
	}
	return 0;
}
string MakeBase3(string N)
{
	string res = "";
	int a = 199;
	int b = -1;
	while (CmpBigNum(N, "0") == 1)
	{
		if (CmpBigNum(N, SNum[3][a]) >= 0)
		{
			N = SubBigNum(N, (SNum[3][a]));
			if (b == -1)
				b = 1;
			else
				b++;
		}
		else
		{
			if (b != -1)
			{
				res += (b + '0');
				b = 0;
			}
			a--;
		}
	}
	res += (b + '0');
	reverse(res.begin(), res.end());
	return res;
}
string MakeBase2(string N)
{
	string res = "";
	int a = 199;
	int b = -1;
	while (CmpBigNum(N, "0") == 1)
	{
		if (CmpBigNum(N, SNum[2][a]) >= 0)
		{
			N = SubBigNum(N, (SNum[2][a]));
			if (b == -1)
				b = 1;
			else
				b++;
		}
		else
		{
			if (b != -1)
			{
				res += (b + '0');
				b = 0;
			}
			a--;
		}
	}
	res += (b + '0');
	reverse(res.begin(), res.end());
	return res;
}
string ZeroASCII[6] =
{
	".####..",
	"##..##.",
	"##..##.",
	"##..##.",
	".####..",
	"......."
};
string OneASCII[6] =
{
	"###.",
	".##.",
	".##.",
	".##.",
	".##.",
	"....",
};
string NineASCII[6] =
{
	".####..",
	"##..##.",
	".#####.",
	"....##.",
	".####..",
	"......."
};
string TwoASCII[6]	 =
{
	".####..",
	"##..##.",
	"...##..",
	".##....",
	"######.",
	"......."
};
string SpaceASCII[6] =
{
	"....",
	"....",
	"....",
	"....",
	"....",
	"....",
};
string CommaASCII[6] =
{
	"..",
	"..",
	"..",
	"##",
	".#",
	"..",
};
string DotASCII[6] =
{
	"..",
	"..",
	"..",
	"##",
	"##",
	"..",
};
string ASCII_Line[6];
void Add_ASCII(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < ZeroASCII[j].length(); k++)
					ASCII_Line[j] += ZeroASCII[j][k];
		}
		else if (s[i] == '1')
		{
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < OneASCII[j].length(); k++)
					ASCII_Line[j] += OneASCII[j][k];
		}
		else if (s[i] == '2')
		{
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < TwoASCII[j].length(); k++)
					ASCII_Line[j] += TwoASCII[j][k];
		}
		else if (s[i] == '9')
		{
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < NineASCII[j].length(); k++)
					ASCII_Line[j] += NineASCII[j][k];
		}
		else if (s[i] == ' ')
		{
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < SpaceASCII[j].length(); k++)
					ASCII_Line[j] += SpaceASCII[j][k];
		}
		else if (s[i] == ',')
		{
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < CommaASCII[j].length(); k++)
					ASCII_Line[j] += CommaASCII[j][k];
		}
		else if (s[i] == '.')
		{
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < DotASCII[j].length(); k++)
					ASCII_Line[j] += DotASCII[j][k];
		}
	}
}
void NextLine_ASCII(string &s,int lineNum = 6)
{
	for (int i = 0; i < lineNum; i++)
		while (ASCII_Line[i].size() < 1000)
			ASCII_Line[i] += ".";
	string temp = "";
	for (int i = 0; i < lineNum; i++)
	{
		temp += ASCII_Line[i];
		temp += "\n";
	}

	for (int i = 0; i < 6; i++)
		ASCII_Line[i] = "";

	s += temp;
}
void Fun7()
{
	SNum[2][0] = "1";
	for (int i = 1; i < 200; i++)
		SNum[2][i] = AddBigNum(SNum[2][i - 1], SNum[2][i - 1]);
	SNum[3][0] = "1";
	for (int i = 1; i < 200; i++)
	{
		SNum[3][i] = AddBigNum(SNum[3][i - 1], SNum[3][i - 1]);
		SNum[3][i] = AddBigNum(SNum[3][i], SNum[3][i - 1]);
	}
	for (int i = 0; i < 6; i++)
		ASCII_Line[i] = "";

	string res = "";
	for (int i = 0; i <= 170; i++)
	{
		Add_ASCII(MakeBase3(SNum[2][i]));
		Add_ASCII(", ");
		if(i == 170)
			Add_ASCII("0.");
		if(i == 20 || i == 29 || i == 36 || i == 42 || i == 47)
			NextLine_ASCII(res);
		else if (52 <= i && i <= 60 && i % 4 == 0)
			NextLine_ASCII(res);
		else if (64 <= i && i <= 82 && i % 3 == 1)
			NextLine_ASCII(res);
		else if (85 <= i && i <= 131 && i % 2 == 1)
			NextLine_ASCII(res);
		else if(i >= 132)
			NextLine_ASCII(res);
	}

	for (int i = 0; i < 1000; i++)
		res += ".";
	res += "\n";
	Add_ASCII("01020102001020021020001020010200120000120001200102010200120120012001200102012001020102012001020102010102010201200120012012001220100200012002010201020102010200");
	NextLine_ASCII(res);
	Add_ASCII("120012012001200120012001200120012001200120012012001201002000102001201200020020010020102001200001020102000120002010200102020000102001202002102001200202010201");
	NextLine_ASCII(res);
	Add_ASCII("0201020010020201020201020200120010001200201200102012001200120102012002100002010200010200012022020012020102020102020102010909909990999909999902010200120012");
	NextLine_ASCII(res);
	Add_ASCII("0012010201020102012001201201020120102012002001020012001200120012000120012001200210200120000120012001201200120102001001001001010100101000020102010200102001020001");
	NextLine_ASCII(res,5);

	cout << res;

}
int D_X[9] = { 1,1,0,-1,-1,-1,0,1,0 };
int D_Y[9] = { 0,1,1,1,0,-1,-1,-1,0 };
char Gen8_Board[1000][1000];
void Fun8()
{
	int x = 500;
	int y = 500;
	string res0 = "B2DCD2E5FEF4G2FG3HG3H2GH5A2HA10BABABAB7C2BC2BC10DC2DCDCD2CD7EDEDEDE3DE9FE3FE2FEFEF2EF9GFGFGFG2FG5FG6HG4HG3HGHGHGH2GH11AHAHAHA2HA2HA17BA3BA2BABABAB2AB3AB7CB2CBCBCBCBC2BC4BC4B3CBC4D7ED2C7BC7DCD2EDE9D5C2DCDCDCD3E3FE2FEF2EFE5D2ED2ED2EDE5F7GF2GF2E14FEF3G2FG11F6EF2EF4G6HGH2GHGH2G5FG2FGFGFGFG6H2GH3AHAHAHAH4G3HG5HG3H6A8BA4HA2H11AHA6BABAB3AB2ABA6HA3HA3HA4BA2B6CBC2BCBCB5ABA2BA2BA2B2AB4C9DC9BCBCB4CB3CBC3BCDC3D2CD6CD2C3DC3BC13DCD6EDE3DE2DEDED6CDCDCDCD7E9FE3FE4FDE4DED2EDEDEDEDE2DE4FE2FEF11EFE2FE10FE4FE2F6GFG2FG4FG3FGFGF8EF8GFG6HG3HG2HGHG3HG5FG2FG2FGFG2FG3FG5HG2H2GH10AH3GHGHG3HG4HG3HGHGHGH5A2HA3HA7HA3HAHAH2AH10AH2A2HA6BA2BA2BABABABA2BA11HA3HA12BA2B10CB2CB7ABABA2BABA2BABAB2AB4CBC2BC11BC7BCBCBCB3CB3CB2CBCBC3BC5DC2DC2D2CDCD2CDCDCDC3DC10BC9DC3DCDCD7EDEDEDED2EDED7CD2CDCDCDCD3CD4EDEDE3DE7FE13DE2DEDEDEDEDEDEDEDE2DE4DEFE4FEFEFEF2EF2EF3EFEFEFEFE5FE10FE4FEFEFEF7GFGFGFG2FGFG2FGF2GF10EF11G2FG14HG5HG9FG3FG2FG2FGFG2FG3FG8HG3HGHGH3GH8GH2GH2G2HGHG3HG4HG3HG2HG2HGH2GH6AHAHA2HA2HA3HA2HA2HAHAHAH10AH5AH2AHA2HA13BA3BA2BA3BA4BA5HA5HA4HA4HA9BA3BABAB2AB18ABABABABA2BA2BABA2BAB2AB3AB4CBCBC2BC3BC4BC5BC3BCBC2BCB2CB2CB4CB2CB2CBCBC2BC13DC2DC2DCDC2DCDC2DC2DC32DC2DCDCDCD11ED2ED12CD2CDCDCDCD2CD2CD8EDEDE2DE4DE11DE6DE3DEDE2DED2EDEDEDEDEDEDE2DE2DE10FE3FEFE2FEFEF2EFEFEFEFE2FE2FE4FE11FE7FE3FEFEFEF2EF8GF2GFGFGF2GFGF2GF12EF2EF13GFG2FG4FG28FG3FG2FG2FG2FGFG2FG2FG3FG12HG2HG2HGH2GHGH2GH2GH2GH2GHGHGHGHG2HG3HG4HG4HG3HG2HG2HGHGH2GH9AHAHAHAHA2HAHAHAHAHAHAH2AH17AH3AHAHAHAHA3HA14BA6BA19HA4HA3HA3HA6HA6BA4BA2BABABABAB3AB6AB4AB3ABABABABA2BABA2BA2BA2BABA2BAB2ABAB9CB2CBC2BC2BC2BC2BC2BC2BC2BCBCBCBCB2CB2CB4CB3CB3CBCBCBCBCBC3BC14DC4DC2DC3DC3DC5DC15BC22DC3DCDCDCD2CD3CD20CD2CDCD2CDCDCDCDCDCDCD2CD3CD7ED2EDE2DE2DE2DE4DE4DE4DE3DE2DE2DEDEDEDEDEDED2EDED2EDEDEDE2DE2DE3DE11FE4FE2FE2FE2FEFE2FEFE2FE3FE3FE6FE17FE6FE2FE2FEFEFEF2EF13GF3GF4GF11EF2EF2EF3EF3EF10GFGFGFGFG3FG3FG8FG10FG5FG3FG2FG2FG2FGFGFG2FGFG2FG2FG2FG3FG13HG3HG2HG2HGHGHGHGHGHGHGHGHGHGHG2HGHG3HG3HG4HG5HG4HG3HG3HG2HGHGHGH2GH12AHAH2AHAH2AHAH2AH2AH3AH25AH2AHAHAHA2HA2HA6HA16BA7HA9HA3HA3HA3HA3HA3HA3HA18BA2BA2BABA2B2ABAB2ABAB3AB2ABAB2ABABABABABA2BABA2BA3BA2BA2BA2BA2BABABABABAB3AB9CB2CBCBCBCBCBC2BCBCBCBCBCBCBCBCB2CB3CB4CB5CB4CB2CB2CBCBCBCBC3BC3BC16DC7DC6DC19BC7BC7BC13DC4DC2DC2DCDCDCDCD2CD4CD5CD5CD3CD2CD2CDCDCDCDCDCDCDCDC2DCDCDCD2CDCD3CD10ED2EDEDE2DEDE2DE2DE2DE2DE2DE2DE2DE2DEDEDEDEDED2EDED2ED2ED2EDED2EDEDEDEDE2DE2DE4DE15FE4FE3FE3FE3FE3FE3FE5FE30FE7FE3FE2FE2FEFEFEF2EF2EF27EF3EF2EF2EFEF2EF2EF2EF2EF14GFGFGFGFG2FG2FG2FG4FG4FG4FG4FG3FG2FG2FG2FG2FGFGFGFGFG2FGFGFGFGFG2FG2FG2FG3FG18HG4HG2HG2HG2HG2HGHG2HGHG2HG2HG2HG2HG4HG4HG7HG6HG5HG4HG3HGHG2HGHGHGH2GH3GH12AH3AH2AH4AH5AH12GH5GH15AH2AHAHAHA2HA2HA3HA4HA8HA12HA6HA4HA3HA3HA2HA2HA2HA2HA3HA2HA4HA5HA11BA5BA2BA2BA2BABABA2BAB2ABABABABABABABABA2BABA2BA2BA2BA2BA3BA3BA3BA2BA3BABA2BABABABABAB2AB14CB2CB2CBCB2CBCBCB2CBCB2CB2CB3CB5CB12CB5CB2CB2CBCBCBCBC2BC2BC3BC5BC24DC9BC10BC5BC5BC4BC6BC18DC4DC3DCDC2DCDCDCDCD2CD2CD2CD2CD2CD2CD2CD2CDCDCDCDCDCDCDCDC2DCDC2DCDC2DCDCDCDCDCDCDCD2CD2CD13ED2EDEDEDEDEDEDEDEDE2DEDEDE2DEDEDEDED2EDED2ED2ED2ED2ED3ED2ED2ED2ED2EDEDEDEDE2DE2DE2DE4DE20FE6FE6FE6FE32DE13FE7FE3FE3FE2FEFEFEFEF2EF2EF2EF4EF7EF5EF4EF2EF2EF2EFEF2EFEFEF2EFEFEF2EFEF2EF3EF14GF2GFGFGFGFG2FGFG2FG2FG2FG3FG2FG2FG2FG2FG2FG2FGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFG2FG2FG3FG5FG14HG5HG4HG3HG3HG2HG3HG3HG3HG4HG5HG8HG12HG8HG5HG3HG2HG2HG2HGHGHGH2GH2GH3GH36GH4GH3GH2GH4GH17AH2AHAHAHA2HAHA2HA3HA2HA4HA4HA5HA4HA4HA3HA3HA2HA2HA2HA2HA2HAHA2HA2HAHA2HA2HA2HA3HA3HA7HA9BA6BA3BA3BA2BA2BA2BABA2BABA2BABA2BABA2BA2BA2BA2BA3BA3BA4BA4BA4BA3BA3BA3BA2BA2BA2BABABABAB2AB2AB18CB3CB3CB2CB3CB4CB29CB4CB3CB2CBCBCBCBC2BCBC3BC3BC4BC7BC13BC11BC6BC5BC3BC4BC3BC3BC3BC4BC5BC20DC4DC3DC2DCDC2DCDCDCDCDCDCDCDCDCDCD2CDCDCDCDCDCDCDC2DCDC2DCDC2DC2DC2DC2DC2DC2DCDC2DCDC2DCDCDCDCDCD2CD2CD17ED2EDED2EDED2EDEDEDED2EDEDED2ED2EDED3ED3ED3ED4ED4ED3ED3ED2ED2EDEDEDEDEDEDE2DE2DE3DE5DE33FE19DE10DE8DE11DE9FE8FE4FE2FE2FE2FEFE2FEF2EFEFEF2EF2EF2EF3EF2EF2EF3EF2EFEF2EFEF2EFEFEFEFEFEFEFEFEFEFEFEFEFEFEF2EFEF2EF3EF16GF2GFGFGFGFGFGFGFGFG2FGFGFG2FGFG2FGFGFGFG2FGFGFGF2GFGFGF2GFGF2GFGF2GFGF2GFGF2GFGFGFGFG2FGFG2FG2FG3FG4FG24HG6HG5HG5HG5HG7HG15HG27HG6HG3HG3HG2HG2HGHG2HGHGH2GHGH2GH3GH5GH7GH8GH5GH3GH3GH2GH2GH2GH2GH2GH2GH2GH3GH3GH16AH2AHAHAHAHAHAHAHA2HA2HA2HA2HA2HA3HA3HA2HA3HA2HA2HA2HA2HAHA2HAHA2HAHAHA2HAHAHAHAHA2HAHAHA2HA2HA2HA2HA3HA3HA8HA9BA7BA4BA4BA3BA2BA3BA2BA2BA3BA2BA3BA3BA4BA4BA5BA6BA6BA5BA4BA4BA3BA2BA2BABA2BABABAB2ABAB2AB4AB22CB28AB6AB16CB3CBCB2CBCBCBCBC2BC2BC2BC2BC3BC4BC4BC5BC5BC5BC5BC4BC3BC3BC2BC3BC2BC2BC3BC2BC2BC3BC3BC3BC4BC8BC8DC8DC4DC3DC2DC2DC2DC2DCDC2DCDCDC2DCDCDC2DCDC2DCDC2DC2DCDC3DC2DC2DC3DC2DC3DC2DC3DC2DC3DC2DCDC2DCDC2DCDCDCD2CDCD2CD3CD17ED3ED2ED2ED3ED2ED2ED3ED3ED3ED6ED9ED8ED4ED3ED2ED2EDEDEDEDEDEDE2DEDE3DE2DE4DE6DE10DE21DE10DE7DE5DE5DE5DE5DE7DE22FE5FE3FE3FE2FE2FEFEFE2FEFEFEF2EFEFEFEF2EFEFEF2EFEFEFEF2EFEFEFEFEFE2FEFEFEFE2FEFE2FEFEFE2FEFEFE2FEFEFEFEFEF2EF2EF2EF2EF17GF2GF2GF2GFGF2GFGFGFGFGFGFGF2GFGFGFGFGF2GFGF2GF2GFGF2GF3GF2GF2GF3GF2GF2GF2GFGF2GFGFGF2G2FGFGFG2FG2FG2FG3FG4FG7FG19HG12HG19HG5FG25FG12HG10HG5HG3HG3HG2HGHG2HGHGHGHGHGH2GHGH2GH2GH2GH3GH3GH3GH3GH2GH3GH2GH2GHGH2GHGH2GHGH2GHGHGH2GHGHGH2GHGH2GH2GH3GH3GH16AH2AH2AHAHAH2AHA2HAHAHAHA2HAHA2HAHA2HA2HAHA2HAHA2HAHAHA2HAHAHAHAHAHAHAHAHAHAHAH2AHAHAHAHAHAHAHAHA2HAHA2HAHA3HA2HA3HA4HA9HA8BA10BA5BA5BA4BA4BA4BA5BA5BA6BA9BA12BA9BA7BA4BA4BA3BA2BA2BABA2BABABABAB2ABAB2AB3AB4AB7AB15AB7AB5AB3AB3AB3AB3AB4AB4AB8AB9CB2CB3CBCBCB2CBCBC2BCBC2BCBC2BC2BC3BC2BC3BC3BC3BC3BC2BC3BC3BC2BC2BC2BC2BC2BC2BC2BCBC2BC2BCBC2BC2BCBC2BC2BC3BC2BC3BC4BC5BC21DC6DC4DC3DC2DC3DC2DC2DC3DC2DC2DC2DC2DC2DC3DC2DC3DC3DC3DC4DC4DC3DC4DC4DC3DC3DC3DC2DC2DC2DCDC2DCDCDCDCDCD2CDCD3CD3CD23ED5ED6ED12ED32ED3ED2ED2EDED2EDEDE2DEDEDE2DE2DE3DE2DE4DE4DE5DE6DE7DE6DE5DE5DE4DE4DE3DE4DE3DE3DE3DE3DE4DE5DE6DE23FE5FE3FE3FE3FE2FE2FEFE2FEFEFE2FEFEFEFE2FEFEFEFEFE2FEFEFE2FEFEFE2FE2FEFE2FE2FE2FE2FE2FE2FE2FEFE2FE2FEFE2FEFE2FEFEFEFEFEF2EFEF2EF3EF5EF13GF3GF2GF3GF2GF2GF2GFGF2GF2GF2GF2GF3GF2GF3GF3GF4GF4GF4GF4GF3GF3GF2GF2GFGF2GFGFGFGFGFG2FGFG2FG2FG3FG3FG5FG6FG19FG31FG10FG8FG8FG11FG16HG8HG5HG3HG2HG3HGHG2HGHG2HGHGHGHGHGHGH2GHGHGH2GHGH2GH2GHGH2GHGH2GHGHGH2GHGHGHGHGHGHGHGHGHGHGHGHGHGHGHGHGHGHGHGHGH2GHGH2GHGH3GH2GH5GH13AH3AH2AH2AH2AHAHAHAH2AHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAH2AHAHAH2AHAH2AH2AHAH2AHAH2AHAH2AHAHAH2AHAHAHAHA2HAHA2HAHA2HA3HA2HA4HA5HA31BA10BA8BA11BA33BA19BA7BA5BA3BA3BA2BA2BABA2BABABABABABABAB2AB2AB2AB2AB3AB3AB4AB3AB4AB3AB3AB3AB2AB3AB2AB2AB2ABAB2AB2AB2AB2AB2AB3AB3AB3AB19CB3CB2CBCBCB2CBCBCBC2BCBCBC2BCBC2BCBC2BC2BC2BC2BC2BCBC2BC2BCBC2BC2BCBC2BCBCBC2BCBCBCBCBC2BCBCBCBCBC2BCBCBC2BCBC2BC2BCBC2BC3BC3BC3BC5BC10BC7DC11DC6DC4DC4DC4DC3DC3DC4DC3DC4DC4DC5DC5DC6DC6DC6DC6DC5DC4DC3DC3DC3DC2DC2DCDC2DCDCDCDCDCDCDCD2CD2CD2CD3CD6CD31CD9CD6CD5CD6CD22ED3ED2ED2EDEDEDEDEDEDEDEDE2DE2DE2DE2DE2DE3DE2DE4DE3DE3DE4DE3DE3DE4DE3DE2DE3DE3DE2DE2DE3DE2DE2DE2DE2DE3DE2DE2DE3DE3DE3DE5DE5DE26FE6FE4FE3FE3FE2FE2FE2FE2FE2FE2FE2FE2FE2FEFE2FE2FE2FE2FE2FE2FE3FE2FE3FE2FE3FE3FE2FE3FE3FE2FE3FE2FE2FE2FE2FEFE2FEFEFE2FEFEF2EFEF2EF2EF2EF3EF24GF4GF4GF3GF4GF5GF6GF8GF12GF7GF4GF3GF3GF2GF2GFGFGFGFGFGFGFGFG2FGFG2FG2FG3FG3FG4FG4FG6FG7FG9FG8FG8FG6FG5FG5FG5FG4FG5FG5FG5FG7FG29HG5HG4HG3HG3HG2HG2HG2HGHG2HGHGHG2HGHGHGHGHGHGHGHGHGHGHGHGHGHGHG2HGHGHGHGHGHG2HGHGHG2HGHG2HGHG2HGHG2HGHGHG2HGHGHG2HGHGHGHGHGHGHGH2GHGH2GH2GH3GH4GH17AH3AH2AH2AH2AH2AH2AHAH2AH2AHAH2AHAH2AH2AHAH2AH2AH2AH2AH2AH3AH2AH3AH2AH3AH2AH2AH2AH2AH2AHAH2AHAHAH2AHA2HAHAHAHA2HA2HA2HA2HA3HA4HA5HA8HA70HA17HA28BA8BA5BA3BA3BA3BA2BA2BABA2BABABABABABABABAB2ABABAB2AB2AB2ABAB2AB2AB2AB2AB2ABAB2AB2ABAB2ABAB2ABABAB2ABABABAB2ABABAB2ABABAB2ABAB2AB2AB2AB2AB3AB5AB15CB3CB3CBCB2CBCB2CBCBCBCBCBCBCBCBCBCBCBCBC2BCBCBCBCBC2BCBCBCBCBCBCBCBCBCBCBCBCB2CBCBCBCBCBCB2CBCBCBCBCBCBCBCBCBCBCBC2BCBC2BCBC2BC2BC3BC3BC3BC5BC8BC19DC10DC7DC7DC6DC7DC8DC10DC12DC13DC10DC6DC5DC4DC3DC3DC2DC2DC2DCDC2DCDCDCDCDCDCDCD2CDCD2CD3CD2CD3CD4CD5CD5CD5CD5CD4CD3CD4CD3CD2CD3CD3CD3CD3CD3CD4CD6CD16ED3ED2ED2ED2EDEDED2EDEDE2DEDEDE2DEDE2DEDE2DE2DE2DE2DE2DE2DE2DE2DE3DE2DE2DE2DE2DE2DEDE2DE2DEDE2DE2DEDE2DEDE2DEDE2DE2DEDE2DE2DE2DEDE3DE2DE2DE3DE4DE4DE5DE29FE6FE5FE4FE3FE3FE3FE3FE3FE3FE3FE3FE3FE3FE3FE4FE3FE4FE4FE4FE5FE4FE3FE4FE3FE3FE3FE3FE2FE2FE2FEFE2FEFEFEFEFEFEFEFEF2EF2EF2EF3EF4EF9EF24GF58GF3GF2GF2GF2GFGFGF2GFGFG2FGFGFG2FGFG2FG2FG2FG3FG3FG3FG3FG4FG4FG4FG4FG4FG5FG3FG4FG3FG4FG3FG3FG3FG3FG3FG3FG3FG3FG3FG4FG4FG5FG7FG25HG7HG4HG3HG3HG3HG2HG3HG2HGHG2HG2HG2HGHG2HGHG2HG2HGHG2HGHG2HGHG2HG2HG2HGHG2HG2HG2HG2HG2HG2HG2HG2HG3HG2HG2HGHG2HG2HG2HGHG2HGHG2HGHGHGHGHGHGHGH2GHGH2GH2GH3GH3GH24AH4AH3AH3AH2AH3AH3AH3AH3AH3AH4AH4AH5AH4AH5AH4AH4AH3AH3AH2AH2AH2AH2AHAHAHAH2AHA2HAHAHA2HAHA2HA2HA2HA3HA3HA4HA5HA6HA8HA12HA13HA11HA9HA7HA7HA7HA7HA10HA28BA7BA5BA3BA3BA3BA2BA2BABA2BA2BABABABA2BABABABABABABAB2ABABABABABABAB2ABABABABABABABABABABABABABABABABA2BABABABABABABABABA2BAB2ABABABABABAB2ABAB2AB2AB3AB3AB5AB16CB3CB3CB2CB2CB2CBCB2CB2CBCBCB2CBCBCB2CBCBCB2CBCBCB2CBCBCB2CBCB2CB2CBCB2CB2CBCB2CB2CB2CB2CBCB2CBCB2CBCB2CBCBCBCBCBCBCBCBCBC2BCBC2BC2BC2BC2BC3BC3BC4BC6BC9BC30DC20DC65DC11DC6DC5DC3DC3DC3DC2DC2DC2DCDC2DCDCDCDCDCDCDCDCDCD2CDCD2CD2CD2CD2CD2CD2CD2CD3CD2CD2CD3CD2CD2CD2CD2CD2CD2CD2CDCD2CD2CDCD2CD2CD2CDCD2CD2CD2CD3CD2CD3CD5CD21ED3ED2ED2ED2EDED2EDEDEDEDEDEDEDEDEDE2DEDEDE2DEDEDE2DEDEDE2DEDE2DEDEDE2DEDEDEDE2DEDEDEDEDEDE2DEDEDEDEDEDEDEDEDE2DEDEDEDEDE2DEDE2DEDE2DE2DEDE3DE2DE2DE3DE4DE5DE7DE27FE8FE7FE5FE5FE5FE5FE5FE5FE6FE7FE6FE8FE7FE7FE5FE5FE5FE3FE4FE2FE3FE2FE2FE2FEFE2FEFEFEFE2F2EFEFEFEF2EF2EF2EF2EF3EF3EF5EF6EF8EF8EF7EF6EF5EF5EF4EF5EF5EF7EF19GF3GF3GF2GF2GFGF2GFGFGFGFGFGFGFG2FGFG2FGFG2FG2FG2FG2FG2FG2FG3FG2FG2FG3FG3FG2FG3FG2FG2FG3FG2FG2FG3FG2FG2FG2FG2FG2FG2FG2FG2FG2FG2FG2FG2FG3FG2FG3FG2FG3FG4FG4FG6FG8FG18HG9HG6HG4HG4HG3HG3HG3HG3HG2HG3HG2HG2HG3HG2HG3HG2HG3HG2HG3HG2HG3HG3HG3HG3HG3HG3HG3HG3HG3HG3HG2HG3HG2HG2HG2HG2HG2HG2HGHG2HGHGHGHGHGHGHGHGH2GHGH2GH2GH2GH4GH5GH28AH7AH8AH12AH19AH10AH5AH4AH3AH2AH2AH2AHAH2AHAHAHAHAHAHAHA2HAHA2HAHA2HA2HA3HA2HA3HA3HA4HA4HA5HA4HA6HA5HA5HA5HA5HA5HA4HA5HA4HA4HA4HA4HA4HA4HA5HA5HA7HA13HA9BA12BA6BA4BA4BA3BA2BA3BA2BA2BA2BABA2BA2BABA2BABABA2BABABA2BABABA2BABABA2BABA2BABABA2BABA2BABA2BABA2BA2BABA2BABA2BA2BABA2BABA2BABABA2BABABA2BABABABABAB2ABABAB2AB2AB2AB2AB3AB5AB21CB4CB3CB2CB3CB2CB2CB3CB2CB2CB2CB2CB3CB2CB2CB3CB3CB2CB3CB3CB3CB3CB3CB2CB3CB2CB2CB2CB2CB2CBCB2CBCBCB2CBCBCBC2BCBCBC2BCBC2BC2BC2BC2BC3BC4BC3BC5BC6BC10BC16BC24BC17BC13BC13BC20BC6DC16DC6DC5DC4DC3DC2DC3DC2DC2DCDC2DCDC2DCDCDC2DCDCDCDCDCD2CDCDCDCD2CDCDCD2CDCDCD2CDCD2CDCDCD2CDCDCD2CDCDCDCDCD2CDCDCDCDCDCDCD2CDCDCDCDCDCD2CDCDCD2CDCD2CDCD2CD2CD2CD2CD3CD5CD22ED3ED3ED2ED2EDED2EDED2EDEDED2EDEDEDEDEDEDED2EDEDEDEDEDEDEDEDEDED2EDEDEDEDED2EDEDED2EDEDED2EDEDEDED2EDEDEDED2EDEDEDEDEDEDEDEDEDE2DEDEDE2DEDE2DE2DE2DE2DE3DE3DE4DE4DE6DE12DE17FE16FE11FE12FE13FE17FE19FE13FE8FE6FE4FE4FE4FE2FE3FE2FE2FE2FEFE2FEFE2FEFEFEFEFEFEF2EFEFEF2EF2EF2EF2EF2EF2EF3EF3EF3EF3EF3EF3EF3EF3EF3EF2EF3EF2EF3EF2EF3EF2EF2EF3EF2EF3EF3EF3EF3EF5EF24GF3GF2GF2GF2GFGF2GFGFGF2GFGFGFGFG2FGFGFGFG2FGFG2FGFG2FGFG2FGFG2FG2FGFG2FG2FGFG2FG2FGFG2FGFG2FGFG2FGFG2FGFGFG2FGFG2FGFGFG2FGFG2FGFG2FGFG2FG2FGFG2FG2FG2FG2FG3FG2FG3FG3FG4FG5FG7FG30HG8HG6HG5HG5HG4HG4HG4HG4HG4HG4HG4HG4HG4HG5HG4HG5HG5HG5HG4HG5HG4HG4HG3HG3HG3HG3HG2HG3HG2HGHG2HG2HGHG2HGHGHGHGHGHGHGH2GHGH2GHGH3GH2GH3GH3GH5GH8GH20GH16GH10GH10GH32AH3AH3AH2AH2AH2AHAH2AHAHAHAHAHAHAHA2HAHAHA2HA2HAHA2HA2HA3HA2HA2HA3HA3HA3HA3HA3HA3HA3HA3HA3HA3HA3HA3HA2HA3HA3HA3HA2HA3HA2HA3HA3HA2HA3HA3HA3HA3HA3HA3HA4HA5HA6HA9HA23BA8BA6BA4BA4BA3BA3BA3BA2BA3BA2BA2BA2BA2BA2BA2BA2BA2BA2BA2BA2BA2BA2BA3BA2BA2BA2BA2BA2BA3BA2BA2BA3BA2BA2BA3BA2BA2BA2BA2BA2BA2BA2BA2BABA2BABA2BABABABABABABABABABAB2ABAB2AB2AB3AB3AB4AB31CB5CB4CB5CB4CB5CB5CB6CB6CB7CB6CB5CB4CB3CB3CB3CB2CB2CB2CB2CBCBCB2CBCBCBCBCBCBC2BCBC2BCBC2BC2BC2BC3BC2BC3BC3BC4BC4BC5BC6BC6BC7BC7BC7BC7BC7BC6BC6BC5BC6BC6BC6BC7BC8BC15BC10DC13DC6DC5DC4DC3DC3DC2DC2DC3DCDC2DC2DC2DCDC2DCDCDC2DCDCDCDCDC2DCDCDCDCDCDCDCDC2DCDCDCDCDCDCDC2DCDCDCDCDC2DCDCDCDC2DCDCDCDC2DCDCDCDC2DCDCDCDCDCDCDC2DCD2CDCDCDCDCDCD2CDCD2CD2CD2CD2CD3CD4CD26ED4ED2ED3ED2ED2ED2ED2ED2ED2ED2EDED2ED2ED2EDED2ED2ED2EDED2ED2ED2ED2ED2ED2ED2ED2ED2ED2ED2ED2ED2ED2ED2EDED2EDED2EDEDED2EDEDEDEDEDEDE2DEDEDE2DEDE2DE2DE2DE2DE3DE3DE3DE4DE4DE7DE9DE29DE71DE21FE16FE8FE5FE4FE4FE3FE3FE2FE2FE2FE2FEFE2FEFE2FEFEFEFEFEFEFEFEFEFEFEF2EFEF2EFEF2EFEF2EFEF2EF2EF2EFEF2EF2EFEF2EF2EFEF2EFEF2EFEF2EFEF2EFEF2EFEF2EFEF2EFEF2EF2EFEF2EF2EF2EF2EF2EF2EF3EF4EF4EF23GF4GF2GF3GFGF2GF2GFGF2GFGFGF2GFGFGFGFGFGFGFGFGFGFGFGFGFGFG2FGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFG2FGFGFGFGFG2FGFGFG2FGFG2FG2FGFG2FG3FG2FG3FG3FG3FG4FG5FG8FG37HG10HG8HG8HG7HG8HG7HG9HG9HG9HG9HG8HG7HG6HG5HG4HG4HG3HG3HG2HG3HG2HG2HG2HGHG2HGHGHG2HGHGHGHGHGHGH2GHGH2GHGH2GH2GH2GH2GH3GH3GH3GH4GH4GH4GH4GH4GH5GH4GH4GH3GH4GH3GH4GH3GH4GH4GH4GH6GH10GH14AH4AH3AH3AH2AH2AHAH2AHAH2AHAHAHAHAHAHAHA2HAHAHA2HAHA2HAHA2HAHA2HA2HA2HA2HA2HA2HA2HA2HA2HA2HA2HAHA2HA2HA2HA2HA2HA2HA2HAHA2HA2HA2HA2HAHA2HA2HA2HA2HAHA2HA2HA2HA2HA2HA3HA2HA3HA2HA3HA4HA3HA5HA5HA9HA27BA9BA6BA5BA4BA4BA4BA3BA4BA3BA3BA3BA3BA3BA3BA4BA3BA3BA3BA4BA3BA4BA3BA4BA3BA4BA3BA3BA3BA3BA3BA3BA2BA3BA2BA2BA2BA2BABA2BA2BABABABA2BABABABAB2ABABAB2ABAB2AB2AB3AB3AB4AB5AB13AB70CB12CB5CB4CB3CB3CB2CB2CB2CBCB2CBCBCBCBCBCBCBCBCBCBC2BCBC2BC2BC2BCBC3BC2BC2BC3BC3BC3BC3BC3BC3BC4BC4BC4BC3BC4BC4BC4BC3BC4BC4BC3BC4BC3BC3BC4BC3BC4BC3BC4BC4BC4BC5BC6BC7BC12BC15DC12DC6DC5DC4DC3DC4DC2DC3DC2DC3DC2DC2DC2DC2DCDC2DC2DC2DCDC2DC2DCDC2DC2DCDC2DC2DCDC2DC2DC2DCDC2DC2DC2DCDC2DC2DC2DC2DC2DCDC2DC2DC2DCDC2DC2DCDC2DCDC2DCDC2DCDCDCDCDCDCDCDCDCDCDCDCD2CDCD2CD2CD2CD2CD3CD4CD7CD19ED5ED5ED3ED4ED3ED3ED3ED3ED3ED4ED3ED3ED4ED3ED4ED4ED3ED4ED3ED3ED3ED2ED3ED2ED2ED2ED2EDED2EDEDEDED2EDEDEDE2DEDEDEDE2DEDE2DE2DE2DE2DE2DE3DE3DE3DE4DE4DE5DE6DE7DE8DE10DE11DE10DE10DE10DE9DE8DE10DE12DE36FE9FE6FE4FE4FE3FE3FE2FE3FE2FE2FE2FEFE2FEFE2FEFE2FEFEFEFEFEFE2FEFEFEFEFEFEFEFEF2EFEFEFEFEFEFEFEFEFEFEFEFEF2EFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEF2EFEFEFEF2EFEF2EF2EF2EF2EF2EF3EF3EF4EF26GF4GF3GF2GF2GF3GFGF2GF2GF2GFGF2GFGF2GFGF2GFGFGF2GFGF2GFGFGF2GFGF2GFGFGF2GFGF2GFGF2GFGF2GF2GFGF2GFGF2GFGF2GFGFGF2GFGFGF2GFGFGFGFGFGFGFGFGFGFGFG2FGFGFG2FGFG2FG2FG2FG2FG3FG2FG3FG4FG4FG4FG7FG9FG54HG30HG39";
	string res1 = "HG16HG9HG7HG5HG5HG3HG3HG3HG3HG2HG2HG2HG2HG2HGHG2HGHGHGHG2HGHGHGHGH2GHGHGHGH2GHGH2GHGH2GH2GHGH2GH2GH2GH2GH3GH2GH2GH2GH2GH2GH3GH2GH2GH2GH2GH2GH2GH2GH2GH2GH2GH2GH2GH2GH2GH2GH2GH3GH2GH3GH3GH4GH4GH11GH12AH5AH3AH2AH3AH2AHAH2AH2AHAHAH2AHAHAHAHAHAHAHAHAHAHAHA2HAHAHAHA2HAHAHAHA2HAHAHA2HAHAHA2HAHAHA2HAHAHAHA2HAHAHAHA2HAHAHAHA2HAHAHAHA2HAHAHAHA2HAHAHA2HAHA2HAHA2HAHA2HA2HAHA2HA2HA2HA3HA2HA3HA3HA3HA4HA5HA7HA11HA20BA13BA8BA7BA6BA6BA5BA6BA5BA5BA6BA5BA6BA6BA6BA6BA6BA5BA5BA5BA4BA4BA4BA3BA3BA2BA3BA2BA2BA2BA2BA2BABA2BABA2BABABABABABABABABAB2ABAB2AB2ABAB3AB2AB3AB3AB3AB4AB5AB6AB7AB7AB7AB7AB6AB6AB6AB6AB8AB31CB4CB3CB2CB2CB2CB2CBCB2CBCBCB2CBCBCBCBC2BCBCBCBC2BCBC2BCBC2BC2BC2BCBC2BC2BC2BC3BC2BC2BC2BC3BC2BC3BC2BC2BC3BC2BC2BC3BC2BC2BC3BC2BC2BC3BC2BC2BC2BC3BC2BC2BC2BC3BC2BC3BC2BC3BC3BC3BC3BC4BC4BC4BC6BC7BC18BCDC18DC7DC6DC4DC4DC4DC3DC4DC3DC3DC2DC3DC3DC2DC3DC2DC3DC2DC3DC2DC3DC2DC3DC3DC2DC3DC3DC2DC3DC3DC2DC3DC3DC2DC3DC2DC2DC3DC2DC2DC2DC2DC2DC2DC2DCDC2DCDC2DCDCDCDCDCDCDCDCDCDCDCD2CDCD2CDCD2CD2CD3CD3CD4CD6CD37ED8ED9ED10ED11ED9ED8ED6ED4ED4ED3ED3ED2ED2ED2ED2EDED2EDEDED2EDEDEDEDEDE2DEDEDE2DEDE2DEDE2DE2DE2DE3DE2DE3DE2DE3DE4DE3DE4DE4DE5DE4DE5DE5DE5DE5DE5DE4DE5DE5DE5DE4DE5DE4DE5DE5DE5DE6DE6DE7DE11DE28FE10FE6FE5FE4FE3FE3FE3FE3FE2FE2FE2FE2FE2FE2FE2FEFE2FE2FEFE2FEFE2FEFE2FEFEFE2FEFE2FEFEFE2FEFE2FEFEFE2FEFE2FEFEFE2FEFE2FEFE2FEFE2FEFEFE2FEFE2FEFEFE2FEFEFE2FEFEFEFEFE2FEFEFEFEFEFEF2EFEFEFEF2EFEF2EF2EF2EF2EF3EF3EF4EF10EF15GF5GF4GF4GF3GF2GF3GF3GF2GF2GF3GF2GF2GF3GF2GF2GF3GF2GF2GF3GF2GF3GF2GF3GF2GF3GF2GF2GF3GF2GF2GF2GF2GF2GFGF2GF2GFGFGF2GFGFGFGFGFGFGFGFGFGFGFG2FGFGFG2FG2FG2FG2FG2FG2FG3FG3FG3FG3FG4FG5FG6FG7FG9FG14FG18FG21FG18FG17FG55HG8HG6HG5HG4HG3HG4HG2HG3HG2HG2HG2HG2HG2HGHG2HGHG2HGHGHGHGHG2HGHGHGHGHGHGH2GHGHGHGHGHGH2GHGHGHGH2GHGHGH2GHGHGH2GHGHGH2GHGHGH2GHGHGHGH2GHGHGH2GHGHGHGH2GHGHGHGH2GHGHGH2GHGH2GHGH2GHGH2GH2GH2GH2GH2GH2GH3GH3GH5GH7GH19AH4AH3AH3AH2AH2AH2AH2AH2AH2AHAH2AHAHAH2AHAHAH2AHAHAHAHAH2AHAHAHAHAHAHAH2AHAHAHAHAHAHAH2AHAHAHAHAHAH2AHAHAHAHAH2AHAHAHAHAHAH2AHAHAHAHAHAHAHAHAHAHAHAHA2HAHAHAHA2HAHA2HAHA2HA2HA2HA2HA2HA2HA3HA2HA4HA3HA4HA5HA7HA9HA41BA15BA13BA12BA13BA14BA13BA12BA10BA7BA7BA5BA4BA4BA4BA3BA3BA3BA2BA2BA2BA2BA2BABA2BABA2BABABABABABABABABABABABAB2ABAB2AB2ABAB2AB2AB2AB2AB3AB2AB3AB2AB3AB3AB3AB3AB2AB3AB3AB3AB3AB3AB2AB3AB3AB2AB3AB3AB3AB3AB3AB4AB3AB5AB6AB27CB4CB3CB3CB2CB2CBCB2CB2CBCBCB2CBCBCBCBCBCBCBCBCBC2BCBCBCBC2BCBCBC2BCBC2BCBC2BCBC2BCBC2BC2BCBC2BCBC2BC2BCBC2BCBC2BCBC2BC2BCBC2BCBC2BCBC2BCBC2BCBC2BC2BCBC2BCBC2BC2BC2BCBC2BC2BC2BC2BC2BC2BC3BC2BC3BC3BC3BC4BC4BC5BC7BC10BC26DC12DC7DC6DC6DC5DC4DC5DC4DC4DC4DC4DC4DC4DC4DC5DC4DC4DC4DC4DC5DC4DC4DC4DC4DC3DC4DC3DC3DC3DC3DC3DC2DC2DC2DC3DCDC2DC2DC2DCDC2DCDCDCDC2DCDCDCDCD2CDCDCDCD2CDCD2CD2CD2CD2CD3CD3CD4CD4CD6CD8CD13CD18CD15CD17CD29ED5ED4ED3ED3ED2ED2ED2ED2EDED2EDEDED2EDEDEDEDEDE2DEDEDEDE2DEDE2DEDE2DE2DE2DE2DE2DE2DE2DE3DE2DE3DE2DE3DE3DE2DE3DE3DE3DE3DE3DE3DE3DE3DE3DE3DE3DE2DE3DE3DE3DE3DE3DE3DE3DE3DE3DE3DE3DE4DE4DE4DE4DE5DE6DE8DE15DE10FE15FE8FE5FE5FE4FE4FE3FE3FE3FE3FE2FE3FE2FE2FE3FE2FE2FE2FE2FE2FE2FE3FE2FE2FE2FE2FE2FE2FE2FE2FE2FE2FE2FE2FE3FE2FE2FE2FE2FE2FE2FE2FE2FE2FE2FE2FE2FE2FEFE2FE2FEFE2FEFE2FEFEFE2FEFEFEFEFEFEFEFEFEFEF2EFEFEF2EF2EF2EF2EF2EF3EF3EF5EF8EF25GF6GF6GF5GF4GF5GF5GF5GF5GF5GF5GF5GF5GF4GF4GF4GF3GF3GF3GF2GF3GF2GF2GFGF2GF2GFGF2GFGFGFGFGFGFGFGFGFGFGFG2FGFG2FGFG2FG2FG2FG2FG2FG2FG3FG3FG3FG3FG4FG4FG4FG5FG5FG6FG6FG6FG7FG7FG6FG7FG7FG6FG7FG7FG6FG7FG8FG10FG14FG25HG12HG7HG5HG5HG3HG4HG3HG2HG3HG2HG2HG2HG2HG2HG2HG2HGHG2HGHG2HGHG2HGHGHG2HGHGHGHG2HGHGHGHGHG2HGHGHGHGHGHGHG2HGHGHGHGHGHGHG2HGHGHGHGHGHG2HGHGHGHGHGHG2HGHGHGHGHGHGHGHGHGHG2HGHGH2GHGHGHGHGHGHGH2GHGHGH2GHGH2GH2GH2GH2GH2GH3GH3GH4GH6GH24AH4AH4AH3AH3AH2AH3AH2AH2AH2AH2AH2AH2AH2AH2AHAH2AH2AH2AH2AHAH2AH2AH2AH2AHAH2AH2AH2AH2AHAH2AH2AH2AH2AHAH2AH2AH2AHAH2AHAH2AHAH2AHAHAH2AHAHAHAHAHAHAHAHAHAHAHAHA2HAHAHA2HAHA2HA2HA2HA2HA2HA2HA3HA3HA3HA3HA4HA5HA5HA7HA10HA15HA76HA39BA21BA10BA7BA5BA5BA4BA3BA3BA3BA3BA2BA2BA2BA2BA2BA2BABA2BABA2BABABABABA2BABABABAB2ABABABABAB2ABABAB2ABABAB2ABAB2AB2ABAB2ABAB2AB2ABAB2AB2ABAB2AB2ABAB2AB2ABAB2ABAB2AB2ABAB2AB2ABAB2AB2ABAB2AB2AB2AB2AB2AB2AB2AB2AB3AB3AB3AB4AB5AB9AB16CB5CB3CB3CB3CB2CB2CB2CBCB2CB2CBCBCB2CBCBCB2CBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBC2BCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBC2BCBCBCBCBCBCBCBCBCBC2BCBCBCBCBC2BCBCBC2BCBC2BCBC2BCBC2BC2BC2BC2BC2BC2BC2BC3BC2BC4BC3BC4BC4BC6BC7BC11BC30DC14DC10DC9DC8DC8DC7DC8DC8DC8DC8DC7DC8DC7DC6DC6DC5DC4DC5DC3DC4DC3DC3DC3DC2DC2DC3DC2DC2DCDC2DC2DCDC2DCDCDCDCDC2DCDCDCD2CDCDCDCD2CDCD2CDCD2CD2CD2CD2CD2CD3CD2CD3CD4CD3CD3CD4CD4CD4CD4CD5CD4CD4CD4CD4CD4CD4CD4CD5CD5CD5CD7CD32ED4ED3ED3ED2ED2ED2ED2ED2EDEDED2EDEDEDEDEDEDEDEDEDEDEDEDE2DEDEDE2DEDE2DEDE2DEDE2DE2DE2DEDE2DE2DE2DE2DE2DEDE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DEDE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DE2DE3DE2DE2DE3DE2DE3DE3DE3DE3DE4DE4DE5DE5DE8DE12DE20FE13FE8FE6FE6FE4FE5FE4FE3FE4FE4FE3FE3FE4FE3FE3FE3FE3FE3FE4FE3FE3FE3FE3FE4FE3FE3FE3FE3FE3FE4FE2FE3FE3FE3FE3FE2FE3FE2FE2FE2FE2FE2FE2FE2FE2FEFE2FEFE2FEFE2FEFEFEFEFEFEFEFEFEFEF2EFEF2EFEF2EF2EF2EF2EF3EF3EF3EF4EF6EF10EF70GF16GF9GF5GF5GF3GF3GF3GF2GF3GF2GFGF2GF2GFGFGF2GFGFGFGFGFGFGFGFG2FGFGFGFG2FG2FGFG2FG2FG2FGFG3FG2FG2FG3FG2FG3FG3FG3FG3FG3FG3FG4FG3FG4FG3FG4FG4FG3FG4FG4FG4FG3FG4FG4FG4FG3FG4FG4FG4FG4FG4FG4FG5FG4FG6FG6FG7FG10FG36HG9HG7HG5HG4HG4HG4HG3HG3HG3HG2HG3HG2HG2HG2HG2HG2HG2HG2HG2HG2HG2HG2HGHG2HG2HG2HGHG2HG2HGHG2HG2HG2HGHG2HG2HGHG2HG2HGHG2HG2HGHG2HG2HG2HGHG2HGHG2HG2HGHG2HGHG2HGHG2HGHG2HGHG2HGHGHGHG2HGHGHGHGHGHGHGHGHGHGH2GHGHGH2GHGH2GH2GH2GH2GH2GH3GH3GH4GH6GH30AH5AH5AH4AH3AH4AH3AH3AH4AH3AH3AH3AH3AH4AH3AH3AH3AH3AH3AH4AH3AH2AH3AH3AH2AH3AH2AH2AH2AH2AH2AH2AHAH2AHAH2AHAHAH2AHAHAHAHAHAHAHA2HAHAHAHA2HAHA2HA2HA2HAHA2HA3HA2HA2HA3HA3HA3HA4HA4HA4HA5HA5HA6HA7HA9HA9HA9HA11HA10HA11HA10HA11HA11HA14HA47BA10BA7BA5BA4BA4BA4BA3BA3BA2BA3BA2BA2BA2BA2BA2BABA2BABA2BABA2BABABA2BABABABA2BABABABABABABABABABABABABABABABABABABABABAB2ABABABABABABABABABABABABABAB2ABABABABABABABABABABAB2ABABABABAB2ABABABAB2ABAB2ABAB2ABAB2AB2AB2AB2AB2AB3AB3AB3AB4AB7AB24CB4CB4CB3CB2CB3CB2CB2CB2CB2CB2CB2CB2CBCB2CBCB2CB2CBCBCB2CBCB2CBCB2CBCB2CBCBCB2CBCB2CBCBCB2CBCB2CBCB2CBCBCB2CBCB2CBCBCB2CBCBCB2CBCBCBCB2CBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBC2BCBCBC2BCBC2BC2BCBC2BC2BC2BC3BC2BC3BC2BC4BC3BC4BC4BC6BC6BC9BC16BC37DC31DC28DC24DC15DC11DC9DC6DC6DC4DC5DC3DC4DC3DC2DC3DC2DC2DC2DC2DC2DC2DC2DCDC2DCDCDC2DCDCDCDCDCDCDCDCDCDCDCD2CDCDCD2CDCDCD2CD2CDCD2CD2CDCD2CD2CD2CD2CD2CD2CD2CD2CD3CD2CD2CD2CD2CD2CD2CD3CD2CD2CD2CD2CD2CD2CD3CD2CD2CD3CD2CD2CD3CD3CD3CD3CD3CD4CD6CD8CD21ED5ED3ED3ED3ED2ED2ED2ED2EDED2EDED2EDED2EDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDE2DEDEDEDEDE2DEDEDEDE2DEDEDE2DEDEDE2DEDEDEDE2DEDEDE2DEDEDE2DEDEDE2DEDEDE2DEDEDE2DEDEDE2DEDEDE2DEDE2DEDE2DEDE2DE2DEDE2DE2DE2DE2DE2DE2DE2DE2DE3DE3DE2DE3DE4DE4DE4DE5DE6DE9DE45FE10FE9FE7FE6FE6FE6FE5FE6FE5FE5FE6FE5FE6FE5FE5FE6FE5FE5FE4FE5FE4FE4FE4FE4FE3FE3FE3FE3FE3FE2FE3FE2FE2FE2FE2FEFE2FE2FEFE2FEFEFEFE2FEFEFEFEFEFEFEF2EFEFEF2EFEF2EFEF2EF2EF2EF3EF2EF3EF3EF3EF4EF4EF5EF6EF6EF7EF7EF7EF7EF7EF7EF8EF11EF32GF5GF3GF3GF3GF3GF2GF2GFGF2GF2GFGFGF2GFGFGFGFGFGFGFGFGFGFGFG2FGFGFG2FGFG2FG";
	string res = "";
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			Gen8_Board[i][j] = '.';
	x = 500;
	y = 500;
	Gen8_Board[y][x] = '#';
	pair<char, int> now = { 'B',0 };
	for (int i = 1; i < res0.length(); i++)
	{
		if ('0' <= res0[i] && res0[i] <= '9')
		{
			now.second *= 10;
			now.second += (res0[i] - '0');
		}
		else
		{
			if (now.second == 0)
				now.second = 1;
			for (int j = 0; j < now.second; j++)
			{
				x = x + D_X[now.first - 'A'];
				y = y + D_Y[now.first - 'A'];
				Gen8_Board[y][x] = '#';
			}
			now = { res0[i],0 };
		}
	}
	for (int i = 0; i < res1.length(); i++)
	{
		if ('0' <= res1[i] && res1[i] <= '9')
		{
			now.second *= 10;
			now.second += (res1[i] - '0');
		}
		else
		{
			if (now.second == 0)
				now.second = 1;
			for (int j = 0; j < now.second; j++)
			{
				x = x + D_X[now.first - 'A'];
				y = y + D_Y[now.first - 'A'];
				Gen8_Board[y][x] = '#';
			}
			now = { res1[i],0 };
		}
	}
	{
		if (now.second == 0)
			now.second = 1;
		for (int j = 0; j < now.second; j++)
		{
			x = x + D_X[now.first - 'A'];
			y = y + D_Y[now.first - 'A'];
			Gen8_Board[y][x] = '#';
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
			res += Gen8_Board[i][j];
		res += "\n";
	}
	cout << res;

}
char Gen9_Board[1003][1003];
vector<string> split(string input, vector<char> check)
{
	vector<string> answer;
	input += check[0];
	string temp = "";
	for (int i = 0; i < input.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < check.size(); j++)
			if (input[i] == check[j])
			{
				flag = true;
				break;
			}
		if (flag && temp.size() > 0)
		{
			answer.push_back(temp);
			temp = "";
		}
		else
		{
			temp += input[i];
		}
	}
	return answer;
}
void Fun9()
{
	string res = "1,812,D,130,2,544,A,442,13,488,A,47,15,636,C,874,21,110,D,54,22,506,C,763,24,146,C,844,27,388,A,116,28,475,D,43,38,296,C,207,39,840,C,611,42,76,C,329,42,408,C,152,46,258,C,64,47,790,A,212,48,0,A,19,50,872,D,528,54,398,C,61,55,703,A,230,59,233,D,233,62,96,C,174,63,854,A,148,64,0,A,296,64,657,D,297,65,428,C,750,66,246,C,278,68,637,B,8,69,824,C,302,70,50,B,831,72,661,D,257,77,856,C,722,80,70,A,863,83,124,C,505,90,396,C,42,91,612,C,817,92,643,B,256,98,84,B,370,99,507,A,4,99,831,D,192,103,736,C,123,106,202,C,43,106,590,B,412,108,827,B,175,109,670,C,92,112,674,C,657,121,898,C,418,124,678,A,324,125,0,A,912,128,454,A,6,129,484,C,707,130,477,D,159,131,707,B,94,135,680,A,130,136,734,C,262,141,872,A,116,143,151,D,151,143,362,A,197,149,816,C,501,150,620,B,202,154,916,B,86,157,429,A,509,158,198,C,427,163,328,C,263,164,207,D,29,167,611,A,310,173,978,B,24,175,978,A,24,176,0,A,314,177,696,C,301,179,956,C,758,180,122,C,790,182,347,A,270,188,374,A,202,191,373,D,3,194,391,D,216,195,24,C,549,199,592,D,304,201,470,B,467,202,0,B,333,205,767,A,136,207,564,C,763,208,236,C,486,212,676,B,29,215,895,D,73,218,780,C,425,226,55,D,55,227,302,A,235,229,348,C,293,230,556,B,446,237,412,D,412,238,84,A,163,242,238,B,185,245,0,B,45,253,303,D,303,256,756,C,322,257,724,A,278,258,0,A,221,259,853,D,249,260,215,B,628,260,964,D,306,261,356,A,601,264,760,C,56,268,874,A,39,278,345,A,108,282,570,C,513,283,454,C,626,283,553,A,345,284,1002,D,294,288,0,B,407,289,401,B,414,291,849,D,584,295,1002,D,244,297,183,D,111,297,192,C,186,297,1002,D,162,298,670,A,332,299,0,A,182,301,338,B,147,302,274,C,569,305,292,B,567,306,312,B,126,306,580,B,149,306,811,D,119,307,102,C,456,312,326,C,384,314,197,A,2,320,739,D,135,321,332,C,556,324,715,D,550,324,887,A,115,325,0,A,339,325,450,C,621,325,677,D,225,345,810,C,562,352,839,B,128,359,586,C,22,362,943,A,59,363,0,A,754,369,501,A,162,369,839,D,457,376,314,C,117,381,772,D,182,384,706,A,101,385,26,C,176,390,941,D,450,396,724,B,278,397,572,B,300,400,746,C,187,406,632,C,224,413,571,D,340,415,99,D,99,417,217,D,72,420,966,A,36,421,0,A,204,421,505,D,331,423,604,C,437,426,643,D,322,427,800,C,202,429,208,B,453,434,944,C,47,436,284,A,300,438,384,D,264,443,322,D,78,453,302,B,182,456,448,B,198,466,686,A,316,467,0,A,94,468,675,A,54,470,958,C,56,473,778,A,80,474,261,A,126,474,867,B,135,480,719,D,73,486,50,A,436,491,119,D,113,502,480,D,56,512,995,D,72,513,478,A,11,517,455,B,126,517,1002,D,48,518,538,C,465,519,166,C,367,523,0,B,107,524,562,B,290,525,830,A,172,526,0,A,213,526,878,A,124,527,0,A,461,529,515,B,142,542,590,D,88,544,376,C,228,552,474,C,396,555,16,B,170,559,1002,D,151,561,69,A,284,564,224,B,141,564,444,B,215,569,881,D,296,574,964,C,32,576,278,A,456,577,514,A,28,577,618,C,370,579,858,B,144,584,606,C,182,587,860,C,33,592,607,A,395,593,0,A,35,606,244,A,651,614,0,B,89,619,446,A,263,620,832,C,258,621,410,A,230,622,490,B,23,624,852,B,150,627,348,B,159,651,987,A,15,652,0,A,517,652,1002,D,108,654,266,C,272,654,483,B,18,657,502,B,199,679,0,B,174,680,0,A,29,681,0,B,100,684,488,A,58,691,349,B,79,696,393,D,2,696,764,C,195,698,402,C,12,698,523,A,130,710,610,C,38,711,377,D,93,717,222,A,369,718,596,D,217,728,0,B,180,736,607,B,230,742,294,B,136,746,38,A,323,750,544,B,157,751,552,C,135,753,444,A,558,754,0,A,83,755,180,C,66,772,355,D,132,772,969,D,222,779,0,B,115,782,980,B,22,783,793,B,54,794,990,C,42,809,0,B,174,812,76,B,54,832,775,A,146,833,898,C,139,834,204,A,6,836,327,B,70,856,360,A,465,857,523,A,15,858,295,A,170,890,529,D,94,893,103,B,86,894,84,B,51,901,566,B,18,917,688,A,189,919,674,D,22,921,934,A,68,922,0,A,299,926,463,D,58,935,371,A,278,938,625,B,58,942,174,B,57,951,403,B,8,957,524,C,18,960,601,A,244,967,903,D,10,992,197,A,746,994,583,A,419,995,0,A,45";
	vector<char> split_c(1,',');
	vector<string> Data = split(res, split_c);

	for (int i = 0; i < 1003; i++)
		for (int j = 0; j < 1003; j++)
			Gen9_Board[i][j] = '.';

	for (int i = 0; i < Data.size(); i += 4)
	{
		int x = stoi(Data[i + 1]);
		int y = stoi(Data[i]);
		int Dic = Data[i + 2][0] - 'A';
		int len = stoi(Data[i + 3]);
		Gen9_Board[y][x] = '#';
		for (int j = 0; j < len; j++)
		{
			x += D_X[Dic];
			y += D_Y[Dic];
			Gen9_Board[y][x] = '#';
		}
	}

	res = "";
	for (int i = 0; i < 1003; i++)
	{
		for (int j = 0; j < 1003; j++)
			res += Gen9_Board[i][j];
		res += "\n";
	}
	
	cout << res;

}
string Base2ToNum(string s)
{
	string V = "0";
	for (int i = s.length() - 1; i >= 0; i--)
		if (s[i] == '1')
			V = AddBigNum(V, SNum[2][(s.length() - 1) - i]);
	return V;
}
string Base16V(string s)
{
	if (s.compare("0000") == 0)
		return "0";
	else if (s.compare("0001") == 0)
		return "1";
	else if (s.compare("0010") == 0)
		return "2";
	else if (s.compare("0011") == 0)
		return "3";
	else if (s.compare("0100") == 0)
		return "4";
	else if (s.compare("0101") == 0)
		return "5";
	else if (s.compare("0110") == 0)
		return "6";
	else if (s.compare("0111") == 0)
		return "7";
	else if (s.compare("1000") == 0)
		return "8";
	else if (s.compare("1001") == 0)
		return "9";
	else if (s.compare("1010") == 0)
		return "A";
	else if (s.compare("1011") == 0)
		return "B";
	else if (s.compare("1100") == 0)
		return "C";
	else if (s.compare("1101") == 0)
		return "D";
	else if (s.compare("1110") == 0)
		return "E";
	else if (s.compare("1111") == 0)
		return "F";
}
string Base2V(char s)
{
	if (s == '0')
		return "0000";
	else if (s == '1')
		return "0001";
	else if (s == '2')
		return "0010";
	else if (s == '3')
		return "0011";
	else if (s == '4')
		return "0100";
	else if (s == '5')
		return "0101";
	else if (s == '6')
		return "0110";
	else if (s == '7')
		return "0111";
	else if (s == '8')
		return "1000";
	else if (s == '9')
		return "1001";
	else if (s == 'A')
		return "1010";
	else if (s == 'B')
		return "1011";
	else if (s == 'C')
		return "1100";
	else if (s == 'D')
		return "1101";
	else if (s == 'E')
		return "1110";
	else if (s == 'F')
		return "1111";
}
string Base2ToBase16(string s)
{
	string V = "";
	for (int i = s.length() - 1; i >= 0; i -= 4)
	{
		string temp = "";
		for (int j = i - 3; j <= i; j++)
		{
			if (j >= 0)
				temp += s[j];
			else
				temp += "0";
		}
		V += Base16V(temp);
	}
	return V;
}
string Base16ToBase2(string s)
{
	string V = "";
	for (int i = s.length()-1; i >= 0; i--)
		V += Base2V(s[i]);
	return V;
}
vector<vector<int>> A_Matrix[71];
vector<vector<int>> B_Matrix[71];
void Fun10()
{
	string result = "";
	string res[3];
	res[0] = "0,0,0,2,2,2,0,0,0,0,80,80,40,40,10,63,00,B0,63,03,52,52,00,A4,52,00,A4,52,A8,A8,A8,A8,A8,A8,C8,C8,7D1,3C0,500,4F0,710,ED0,E30,7D1,B91,EB3,612,4A0,A13,BE2,DD1,FE2,303,B02,A13,000,000,000,000,000,000,000,000,000,000,000,398,BD4,C7C,971,772,3B3,68B,FD2,E99,CBF,52F,E6E,9A80,9A80,9A80,9A80,9A80,9A80,9A80,9A80,9A80,9A80,9A80,0000,4491,A841,36F2,D3A2,8981,36F2,8550,8981,5262,8550,2DB1,3E83,C000,2DB1,3E83,C051,C051,F273,5572,9FA2,6750,AD80,0A81,0000,A701,6750,C051,C051,AD80,5572,F23E,566A,0C30,F23E,566A,F2CE,B497,565A,EECD,F23E,566A,0C30,F23E,566A,F2CE,B497,DDBB1,00060,DDBB1,00060,DDBB1,4F4F0,DDBB1,4F4F0,DDBB1,4F4F0,4F490,4F4F0,4F490,4F290,4F490,4F290,4F490,52521,52521,52521,00000,52521,52521,52521,52521,52521,52521,52521,00000,52521,52521,52521,52521,52521,52521,63601,00136,46A95,635C2,63601,100C4,46A95,6FAF1,EE1E1,100C4,CBD75,6FAF1,EE1E1,DB347,CBD75,FDC10,2A161,4A9A6,13E31,57C12,83D93,E89E9,5BA3A,36547,66FD9,F3B73,0BCB2,AC3CB,E12CE,CC43E,57C12,F6652,E89E9,59B91,74367,66FD9,B814F,36547,BB757,008100,008100,008100,008100,008100,008100,008100,008100,008100,000000,000000,000000,000000,000000,000000,000000,000000,000000,000000,000000,000000,FEAED3,8252D1,FD3DB0,7C0C81,6C0C02,FEAED3,1393E0,FD3DB0,81C1B2,000000,FEAED3,1393E0,FD3DB0,FE6ED3,000000,35D523,1393E0,D82810,FE6ED3,FE6E50,35D523,1393E0,000650,5F8A60,E85D27,ABC845,9B88C0,6F0CD5,4E2520,80ED20,AFC2F5,3C2C64,81E760,7E65A5,36E6C4,791917,000650,5F8A60,E85D27,ABC845,9B88C0,6F0CD5,369627,80ED20,AFC2F5,BF8791,219442,A8B474,298442,08B167,6CEDED,BF8791,219442,A8B474,298442,08B167,6CEDED,BF8791,219442,A8B474,9A8252,08B167,6CEDED,BF8791,219442,A8B474,9A8252,08B167,6CEDED,4762FA0,097CFD0,6561B30,6F960C0,AED1E81,CF7DC71,D739361,594BEB0,2014060,87EEED1,21AD060,E700111,F0B8EF1,ED455D1,4DF24B0,37EB340,CF7DC71,AC10661,3167E70,7B1E620,4762FA0,097CFD0,4AB19A0,6F960C0,ED455D1,E0EF6F1,7E1B4C0,3AFEE50,D991183,C73ADB3,2541D42,C303AB3,86B7321,E187AC3,7F0C4E2,D8C6181,A6E3B41,D5002A3,1BCD002,C37BF83,1DC8812,7E1B4C0,8DFEF13,D991183,E36EBE3,C056381,86B7321,56F5C90,7F0C4E2,0486F30,D8C6181,5F22556,79CEA82,3A07C84,20FDF70,C570063,3FD6436,D5BA4E3,3CAE9D0,939AF27,5772BF6,F73EAE7,1E03614,7CFE6E0,70E6BC0,1D02182,B8D6A21,5F22556,79CEA82,3A07C84,73F7C76,C570063,3FD6436,D5BA4E3,3CAE9D0,6C35BE0,5772BF6,F73EAE7,64B5199,2DE38CB,C815C00,EE2955C,55AA92B,6399C06,DA43AA5,571AFEF,803ABC1,43E9456,C0A3BD0,75917BB,D62CA2C,DFC773E,071045F,18710E0,6F55DDE,1DDFC3A,803ABC1,C236885,4F4269E,9966272,58642B0,64B5199,495D892,C815C00,EE2955C,55AA92B,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,00000000,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,00000000,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,25A4A490,5D4DEDB1,FB9AEA22,EDB94D63,28BB2113,568FAE81,D15B77E2,ABBD1522,3D141BB3,4208DC90,3CF10F93,205B1683,FB055C71,493AC0A2,90839741,487261C3,32741D13,784DB601,B8816E80,E5A7E8B0,9502CDA0,BF540262,1CFC9D93,A11D2EB3,A4BD2452,5D4DEDB1,D42D04C1,1B8B0630,28BB2113,568FAE81,F199A073,199B43C5,3BD552F3,DFB9F6F5,E6EE4C36,EEAF15C6,84430196,0642F457,165337D5,230C6902,14DC2672,EEAF15C6,51AF1ED4,3B0B9A80,F5377EB2,1EACC6B6,99DBFE53,FF243667,B16632C2,F7C25210,E9EB65A0,9A740EB4,DFB9F6F5,04EAB510,1C3CB670,84430196,199B43C5,165337D5,154E0341,A54FD0A0,EEAF15C6,8CECFC11,63909272,140F7B9F,263935CA,27051B33,FDDEB0A7,C0E41F1F,616C1CEF,260503CC,457596BE,63909272,140F7B9F,C7E80FF0,27051B33,FDDEB0A7,C0E41F1F,616C1CEF,60503216,457596BE,63909272,140F7B9F,C7E80FF0,27051B33,FDDEB0A7,42A5B757,616C1CEF,60503216,457596BE,63909272,436967B0,C7E80FF0,A544B37B,FDDEB0A7,A65616C00,45A539AD0,0BDF41281,B5B1A76C0,5FF41AD90,A4F317F21,DE6A0A471,ED755DBB1,CF8969E80,5FF41AD90,F7811EBC1,763F5CAB0,5E82190C0,C55E59891,2D7B15B90,E1CF0CA10,763F5CAB0,1B4D13790,C55E59891,FA136CE30,A052E4CE0,CBF829551,5B8F09F61,F3DF1EEB1,727A7E561,A052E4CE0,00D872CE1,A5C7D43D0,340CC4161,6C166DD51,1EB663191,451BAABB1,A5C7D43D0,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,525299890,DE18DB1B3,8C4A42923,8C4A42923,8C4A42923,8C4A42923,F9591F0E7,687CCF5F0,C4E8AC9A2,84E6C1C93,45727EAB1,B38050764,BFE644CB6,42974E411,60BF3E332,DF4C9CCA5,6E2729A00,E8739E7A3,854201E82,208CE0332,84A635C10,E59F8AB71,560FA9A35,91FA635D6,558558956,F9591F0E7,687CCF5F0,AA53C25E0,84E6C1C93,45727EAB1,B38050764,43BA5E050,42974E411,60BF3E332,DBF1EA4F5,6E2729A00,E8739E7A3,854201E82,49508E2E0,84A635C10,E59F8AB71,4949C8292,000000000,F6C6CED8D,F6C6CED8D,4949C8292,000000000,F6C6CED8D,F6C6CED8D,4949C8292,000000000,BF8F06F1F,F6C6CED8D,4949C8292,000000000,BF8F06F1F,F6C6CED8D,4949C8292,000000000,BF8F06F1F,F6C6CED8D,E52525A4A,000000000,BF8F06F1F,F6C6CED8D,E52525A4A,000000000,BF8F06F1F,BF8F06F1F,E52525A4A,000000000,BF8F06F1F,BF8F06F1F,E52525A4A,000000000,BF8F06F1F,BF8F06F1F,CE93B8D370,97F8778E11,023B945C61,5A09F62B81,3A972649F0,A6425CC840,2024D0B240,FD97DB6F50,B25B6FE0A1,134C0618E1,512F9EF441,6CEC618D91,D637E366E0,FFE1172150,BACC073351,CE93B8D370,E42B1DF261,023B945C61,A8DC2DAD31,3A972649F0,A6425CC840,2024D0B240,B912824FE0,B25B6FE0A1,134C0618E1,090E74F761,6CEC618D91,D637E366E0,FFE1172150,3C4E06E961,CE93B8D370,E42B1DF261,65F998B251,A8DC2DAD31,3A972649F0,E2C705E8F0,2024D0B240,07DCA43C10,00AC347010,C8A18C2A33,F266509EF3,45FA40E531,19C098F750,56B3C38841,E29159FA83,40CCC3C201,CD33522623,026BDBB920,DEF5CA3A53,CC15B9D333,532ED23241,34E06C09E0,0988E11920,415C2FB131,99CEFA3172,D8D0251653,82E3510522,E9CA7D1983,1B4090E270,9CD6505062,C42E466023,D2F0418743,C42E466023,F32B6A84F3,2F3F102580,FC86E34CE3,FD9256E2D3,2079997990,B3892EDAE2,33301A14E0,07DCA43C10,A108349092,C8A18C2A33,00AC347010,45FA40E531,CBE4AA7524,F099341A47,E469F59837,5204034DC0,6C64198282,552C70AB47,3C3DC882F1,163EF1C147,390D492161,DE4721D0D4,3EBE34C5C7,14C2D787C2,446BC08DB1,D012941962,E1D7D43AA2,8055831F00,674966E505,5900AA2644,0AC9724C07,45EE21AC85,FD9AFFBAC7,F1340E3BC0,966F1FD373,D6DE0DDD51,DFF8C5F041,8055831F00,B33C577943,B9D67B3E76,99AB533BF3,CBE4AA7524,F099341A47,E469F59837,5204034DC0,6C64198282,D89FBD1367,3C3DC882F1,163EF1C147,390D492161,DE4721D0D4,6179F56E95,977A19B17D,67122664B9,FCB8AD9CCC,61AFC82583,0D54FA2C03,CF1930B332,D9D64B3859,BF943631C2,87D59B7D14,0E10124C39,9E655A547A,784AFF44C7,C3CCC1FD01,5EE5FACC4C,BA5187D3E0,D4EBE1935A,FC847A15DF,233974E9BD,977A19B17D,FEA93C93CA,FCB8AD9CCC,9FAEA9B66F,AAF97C1BBD,315E5CA3DB,D9D64B3859,31558CA4C3,87D59B7D14,2C74D705BE,A4026D9490,784AFF44C7,EEAD75D69D,5EE5FACC4C,4321CA633B,3782ADE2CA,E3AC4674BD,233974E9BD,09F622E63C,FEA93C93CA,7306566AE1,FCA4AC20BC0,B3AA4D19CD1,C9B6F11B261,FCA4AC20BC0,9D412A61040,28BA568E811,FC552CC3840,A9386E73870,28BA568E811,538A6B64130,78F5354BF41,72D74FB6CA1,7CE82EEDBD0,1566A86D561,2B9BE40BF70,3B884EC8A90,1566A86D561,B94D9480E11,3B884EC8A90,0EEF2AF87F1,375B7C4F851,BD23CC8C800,ADA79434A80,375B7C4F851,0BCDA8E15D0,ADA79434A80,7ED16656F00,2377DC16A60,71610F48CA0,7855C592BA1,C0F2A9FF600,75AF4D15A70,7855C592BA1,C0F2A9FF600,CFC349694A1,2AB124328E1,1AF109A3300,E2D9843FBB0,0AD569262E1,6ED29DD6F81,E2D9843FBB0,1D1E204E543,43F7FB324D0,7271CEC5E90,205AE3F8D00,E8414E45932,DCF36304433,1AE5E4D9582,02FDE934680,4FFFBF7D2D3,0CBDC7FD003,573A4D276D1,0F72E9F94C3,F9C781B2F72,5C9F2B0E213,CBAFB7C74F2,02F13077680,999403D2462,945E5A0D521,945E521D521,4B8B97E06D2,9651EDDF1A1,A0AF21B5F20,EF3CDB50CF3,1D1E204E543,22E3A184A80,43F7FB324D0,3E3809C2883,205AE3F8D00,DCF36304433,D69299821B1,02FDE934680,BC9D092DE23,0CBDC7FD003,60D1E5AEC10,573A4D276D1,9EBFECDE2A3,F9C781B2F72,710A1BE2C50,69228119C52,999403D2462,0728669E7C1,945E521D521,67011D28914,3B436C39B07,E40BBEEE937,08E74AA3704,AD427018D63,06CB65C9644,A5430351FA7,376D60ADA04,447DCEF75D5,D8D97E05530,350DFF09984,0824652D404,07881CEE2C2,16BC2398645,B538AE2FD65,A256882D964,F67624F9976,8154A1C2164,A50D6FA1A62,013EB530182,CAEF631A6B2,7BDFDA6CFD6,68A1155AAD1,389E045C9C6,0967809C282,5BF63D465D6,013EB530182,4A802BC9152,084C45905C1,9F8E6CB1026,C6C2267F1B2,7DAA4762F93,CE375C86777,67011D28914,3B436C39B07,EF225DB2DF5,08E74AA3704,AD427018D63,FD2E053CCB3,A5430351FA7,67011D28914,447DCEF75D5,D8D97E05530,A13D1715A6F,E11CE81D8B4,90F8B82602C,4312B649114,BABE9344D6E,379E2BD7D05,C9CDD6276B1,E68B6BD0BB2,8B1149602E5,05F240A00CF,A9037B1BEA2,F6BF4ACDABD,3B301E7D80D,6C982688C56,0928793B58A,9FD3ABD2727,9FAB93C722B,8248E37A5A0,E9F3A32EA7D,7509C5A0E92,3379A972E0F,1886F112183,AF3604C4C6D,29E90419A0B,451656BF195,946856854A8,D51023A5176,AF3604C4C6D,0E85A4EB743,EB3E7A7F9BC,3B056940BC2,A13D1715A6F,E11CE81D8B4,90F8B82602C,4312B649114,BABE9344D6E,379E2BD7D05,C9CDD6276B1,E68B6BD0BB2,8B1149602E5,05F240A00CF,A9037B1BEA2,F6BF4ACDABD,3B301E7D80D,01D660868641,13048142ED00,22D5ECBB0541,137DAF2DFEC1,2DBA639722E0,AD84F44E2C20,DC6A2C26C6A1,0E08B5F43C20,6A901EE93B60,01380FA392D0,C6B14D9C30C0,C8A0FBCFBEA0,E0ACC4443590,731D530CFE40,70B4E19E44D0,CB41C75B2F21,0A4BE3C73421,3DDCD0D9F471,22D5ECBB0541,CF06EA5FBA20,2DBA639722E0,9F0E01896620,DC6A2C26C6A1,4156A7180941,6A901EE93B60,377C144EF4C1,115BBF17CD51,C8A0FBCFBEA0,3D8E773C5630,B82C74B85CA0,24D01AA08051,AAA563F486A0,0A4BE3C73421,4EFDFB1D22E1,D54499B5EE01,CF06EA5FBA20,1DE8214DF2A1,9F0E01896620,E15F06D78351,971148C6C840,6A901EE93B60,5D0F216A5E20,115BBF17CD51,1C6A376DFAA1,3D8E773C5630,72D9FF49F940,A262E5349AB2,6FAAD1EE4BB1,C5A839DF01A2,641C00E95730,2E9379CB6E21,97844E988872,72D9FF49F940,A262E5349AB2,6FAAD1EE4BB1,18A3B306B6C1,641C00E95730,2E9379CB6E21,DBBB771CA9D2,72D9FF49F940,BA076A3AFC73,6FAAD1EE4BB1,18A3B306B6C1,FBFE731C1FD3,2E9379CB6E21,DBBB771CA9D2,72D9FF49F940,BA076A3AFC73,4F5FE48B2B11,18A3B306B6C1,FBFE731C1FD3,B211565AFA73,DBBB771CA9D2,57FA5B868DE0,BA076A3AFC73,4F5FE48B2B11,9FE24FFD5EE3,FBFE731C1FD3,B211565AFA73,B1B7873630C2,57FA5B868DE0,9182BE305052,4F5FE48B2B11,9FE24FFD5EE3,E63BE1DE7D83,B211565AFA73,B1B7873630C2,57FA5B868DE0,9182BE305052,5F9A66805D71,9FE24FFD5EE3,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,000000000000,D7F7FBFD7F7F,85ADB1B7B7F6,7B736F6CEDED,D7F7FBFD7F7F,85ADB1B7B7F6,7B736F6CEDED,D7F7FBFD7F7F,292523262564,7B736F6CEDED,D7F7FBFD7F7F,292523262564,7B736F6CEDED,D7F7FBFD7F7F,292523262564,7B736F6CEDED,5A4A4A4A4989,292523262564,7B736F6CEDED,5A4A4A4A4989,292523262564,D7F7FBFD7F7F,5A4A4A4A4989,292523262564,D7F7FBFD7F7F,5A4A4A4A4989,292523262564,D7F7FBFD7F7F,5A4A4A4A4989,081C06008100,D7F7FBFD7F7F,5A4A4A4A4989,081C06008100,D7F7FBFD7F7F,5A4A4A4A4989,081C06008100,D7F7FBFD7F7F,8DBDB1B736F6,081C06008100,D7F7FBFD7F7F,8DBDB1B736F6,081C06008100,F6C2D8D85A1B,8DBDB1B736F6,081C06008100,F6C2D8D85A1B,8DBDB1B736F6,081C06008100,F6C2D8D85A1B,23F909A45A561,673E2D2C40D81,4ACF53C8CCD80,2659AA3090890,36266569AFAF1,164E075F7B941,F46C365C3E7A1,6FB084CB4FF80,4037A35D0EAC0,4ACF53C8CCD80,DC114628F2D41,8E307190DF4C0,164E075F7B941,E890BBAE2E080,6FB084CB4FF80,040187B020550,A93E8E3B48691,DC114628F2D41,8F272A355D371,C2CFE898C5A31,AB40C808DECA0,8DE4A71625F40,040187B020550,6E80625674920,E42C379EE88A0,13BFCE66271E1,E47F96448FBD1,4EEB0E0DAFC91,E60A0647AF681,040187B020550,3481F84CE4AA1,D366B4AC9EE91,13BFCE66271E1,5320BD4456771,4EEB0E0DAFC91,6BA61A24073D1,2B5B0AADBC201,3481F84CE4AA1,E64E7B0E461F1,920FFD8C83DC0,BDFC64E47F8F1,A43754660B810,6BA61A24073D1,2C7090D83E7C0,175B388BB11C0,E64E7B0E461F1,6CC08E0448040,D3BEC4868A9B1,A43754660B810,3CA931AA7E161,DD2E436B71B20,E3706898860E1,F10BC2DF7C090,0E6A91D604D63,907744AFD9A11,3C5222CE6E7A1,436D4DDC2E292,005064D6882B3,75431FB9CCB11,3CA931AA7E161,4FA5102E96B63,19D50E69D3CE2,80AE1564B08F2,0E6A91D604D63,740B907170B30,A829D63C356B2,B303036ED86A2,A90EAD8634E42,75431FB9CCB11,96422FC270B02,DF246845DBB50,19D50E69D3CE2,199D1393C3C01,8D90FB03397E1,62F7250C21C93,E30C3D8432693,995F95746A6D0,A90EAD8634E42,70FC4D3DDB600,038944C5AEC60,E5FBFCE50FBA0,7A067ACD68422,AA69003C8FCC2,8D90FB03397E1,7309FBC3DE010,9AAB50B9CD681,473979601EB70,B3627BD8D1403,70FC4D3DDB600,B6F2EF66C5770,92AF6F0E7F2E3,7A067ACD68422,BDA3EC73621B3,C5D4F0BF85FC3,3DAD137070BF3,9AAB50B9CD681,2C37221134991,23971E6531E40,041575AA15340,E3BACCE6D3052,8796947D229D2,089E641363665,D06D0E0C10463,BBFC8D8C91DB2,91B41045290D5,5D0C6B3D46F05,89F7669C79D46,E2FDB8B2B4F06,A1F700EDB6FB0,E687123FB8D25,54089A730D2F6,C59A68E227992,0801B52D2CD72,5FB18F977EF50,F975BE3CE8DE4,9208001005F34,711E6CFDF97B3,4BD2008412601,C4301AD64F245,32596D79A8B52,BA73C84095EE0,B8B9F39BFDE90,F996001394626,EE811552883E3,E3BACCE6D3052,0992286F14966,089E641363665,D06D0E0C10463,2AF5188CB7E02,91B41045290D5,5D0C6B3D46F05,89F7669C79D46,E2FDB8B2B4F06,3E385E18F4CC0,E687123FB8D25,C7BFE1BA4FDE5,C59A68E227992,B8FBFFAFC2147,5FB18F977EF50,F975BE3CE8DE4,0A065C8D07134,711E6CFDF97B3,4BD2008412601,C4301AD64F245,32596D79A8B52,92E513C345743,B8B9F39BFDE90,33BFDCCA8FF66,EE811552883E3,306DEAAF904A3,13A8A67063D23,9E442F4F7361E,BC764717DFE9F,77151077E464E,76577754F96D8,2C380C19B0A00,35528F2FE739E,D8B161047DA69,10D6F911685B3,E950AE35A571A,8ECAB458263B2,0D2E6CBB3CA86,D3DD237564679,49AF1035128EA,C446BB8127593,43A34B621E8E6,6E0402DB91207,B21BA3D3C51C7,1787DA666D3EC,F1DE6F34DA6BA,8B1F24ED232C8,6A050855A704A,2D67A43D859D8,B3A2046EC0AAE,586DFF0958950,8A906CC22C025,C24C155B32014,5C53D4855D7D8,AF89D77C9D36A,13A8A67063D23,9E442F4F7361E,BC764717DFE9F,77151077E464E,B4A2D31ACABA5,2C380C19B0A00,35528F2FE739E,D8B161047DA69,610068A4AC609,E950AE35A571A,8ECAB458263B2,AE81715F9E46E,D3DD237564679,49AF1035128EA,C446BB8127593,43A34B621E8E6,6E464E4D9E49B,B21BA3D3C51C7,1787DA666D3EC,F1DE6F34DA6BA";
	res[1] = "F0726980ECC92,6A050855A704A,2D67A43D859D8,EA3988EB26E9F0,24488536A852A1,19BA85D304E771,B97D4278A78EA0,ED53779C6350F0,8C46457D1F3911,C9979F3F3E7E30,B9552CF1A22D40,97C69D6A931D71,85B6BB00EFA481,9A6C6645369771,A51A3102632840,F9BA88714FA711,4936C7DF888320,75D5F4B9350171,7A1956F8111261,04CE9071E55060,F35AE948BF1230,BFFDAC110BBC21,EE472B44132B11,7CAA801B19F901,CD0A59BB1245B1,D25D37B57F3D61,83F836A6A688F0,E37AD59A46B411,252F714340B931,EE2194DFAA8A71,B9F7BF68AEC741,2F53617F304B00,AAABF1723A9D81,6CF589947581D0,BB769F79EFEA11,066E6BC9999FD1,A177F92F86C380,D765F0BF3EC8C1,417C12F17999A0,3C5F2D015453C0,E9479308C740E0,6CC2CD91600030,0AB881C3688440,ACBBDBCD83F650,EA3988EB26E9F0,093CE36BB9EBC1,19BA85D304E771,2839870224C280,EA3988EB26E9F0,8C46457D1F3911,8124DB62929B21,B97D4278A78EA0,ED53779C6350F0,85B6BB00EFA481,C9979F3F3E7E30,429EFBCEF92AD0,7F76E91CC28B91,AC4D77EFABF6F1,E94D6A0DA1A4B1,E7DDD4EBBBA573,4E318B20281700,C5587E1F0180E1,F2CEFC5FD5FAF3,320618E2CC1B50,7F76E91CC28B91,547B5AAB651F61,E94D6A0DA1A4B1,E7DDD4EBBBA573,8448EF2D0313A1,FC5E42B9CFFB31,F2CEFC5FD5FAF3,320618E2CC1B50,CD9910C333D462,547B5AAB651F61,7E4E569BC90971,39DF44B9FB1D33,072811B30DF260,FC5E42B9CFFB31,F2CEFC5FD5FAF3,5F1A94834DC960,CD9910C333D462,71BF95E3F1BD72,7E4E569BC90971,8C103D460270C0,072811B30DF260,FC5E42B9CFFB31,A2848E60908012,5F1A94834DC960,EAD5683CB0B793,71BF95E3F1BD72,A4EDC939B7E633,8C103D460270C0,A1BCA8F59B93B2,3E47E7ECEC4E91,A2848E60908012,C819A8152564A0,EAD5683CB0B793,5BDB7C4F773CE3,A4EDC939B7E633,37BE8351D1DB32,A1BCA8F59B93B2,3E47E7ECEC4E91,F30E9293CD2B70,F54649C8C64B11,AE6D7A3FA945F1,5BDB7C4F773CE3,A1655D2AA2A651,37BE8351D1DB32,A1BCA8F59B93B2,5A8399A27C8E42,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,A8F81323151364,D7090ECC5A14CA,5FA3965A48C5A8,631905FF983574,DD908B1362BE5E,60C418B45C9E60,539396AB402F19,EB279479713BD3,660903B0610820,7A7B79852201DA,86302360344BD0,1C8C44805B55BC,4D4160FD1E6881,E0CD190C464CC6,126073C880EA1F,C68C9AB9008516,3A9858EA0E5E6D,9907E904BECC98,C8DE134A155D43,38FFD6FCD6D5C9,5EF8B4D5B9FFDE,0F2D50A0CCBEC3,FC4C227DD3B65A,16C196FCA8D719,2303ADD977A757,F3EFEE8FD979E8,FFCC170039422F,E2B59E3F98FAD4,7AFC79EDFF2548,EA884BAB5B1E42,33226D53EF423B,8C55E8902C5511,2D3AD2E897C4B5,602E1A5A67BEF6,1EB2C28D8E7B5B,E5D7D8417A8FB1,F62E47E610B2BF,94B3AE29476989,254731E744AA36,8478D132DF01B6,6C3A5B5C4489B0,BEFD469FDF3709,D7090ECC5A14CA,5FA3965A48C5A8,BB293312D3396D,DD908B1362BE5E,60C418B45C9E60,539396AB402F19,5EFD02C97FBA68,660903B0610820,7A7B79852201DA,50725E84770F79,1C8C44805B55BC,4D4160FD1E6881,E0CD190C464CC6,056F852B27A187,C68C9AB9008516,AF5751D2FDCF330,E8FD291EC0EB880,18904EDFC9FC121,2B12D66DA49C271,7C02E8E5A5717F0,0290A8AD679C4E0,369E59F77170040,C4785B2B587C8C0,3F822F2CCF391A1,7C6F69ACE698F40,0462CEF03701EC1,8E6815030E46791,054018CF92D5370,424561E5DB5CC50,C7199B81FD0E640,99B762F0222FF90,2B261FFDAF2A361,8ED31775E4C8F71,2C69ECB8FBAAE41,1B50250CF696551,92C0F4F46D1C091,3E838546A3A9871,E31D7C883124511,E8FD291EC0EB880,CE92CBF68E66050,86875D97C7C3E21,7C02E8E5A5717F0,689DB9F61B25D10,3152832E16AD490,52CD4D651980221,3F822F2CCF391A1,B05199CB14B2CB0,D57F68247F23D10,127593CA136B580,054018CF92D5370,BF045FFD38C4161,C672C5A9CE776B1,CBD8B7A0533A531,46BE723ACB389F0,E816B55A4547FB1,CAC7F7F803E1381,1F1600E97B0D010,465B97672D9F021,3E838546A3A9871,D791B21127CBBB0,A966568500B6E81,859B08D572C6F70,86875D97C7C3E21,3E7B5B320A75CD0,BF2C58E89E6E110,C239385A10E87C0,52CD4D651980221,4CAD1B460EBC4C0,1B2EA8E9BE98B40,D57F68247F23D10,4F436C8A351E561,2C5A02E1011F630,100000C00000083,A8741F8D82E1542,392525A4A4A49C2,6A2D45A5A9A43D0,66ACC49599923B0,D49992303356621,100000C00000083,100000C00000083,130360636C0C893,392525A4A4A49C2,1A4149EB28250D3,1A4149EB2825050,0942294B44298C3,100000C00000083,A8741F8D82E1542,392525A4A4A49C2,6CED8D7DB1B7363,1A4149EB2825050,D49992303356621,100000C00000083,100000C00000083,130360636C0C893,392525A4A4A49C2,66ACC49599923B0,1A4149EB2825050,0942294B44298C3,100000C00000083,A8741F8D82E1542,392525A4A4A49C2,6CED8D7DB1B7363,1A4149EB2825050,D49992303356621,100000C00000083,100000C00000083,392525A4A4A49C2,392525A4A4A49C2,66ACC49599923B0,1A4149EB2825050,0942294B44298C3,100000C00000083,130360636C0C893,392525A4A4A49C2,6CED8D7DB1B7363,1A4149EB2825050,430860010D00A91,100000C00000083,100000C00000083,392525A4A4A49C2,392525A4A4A49C2,66ACC49599923B0,1A4149EB2825050,100000C00000083,100000C00000083,130360636C0C893,392525A4A4A49C2,6CED8D7DB1B7363,1A4149EB2825050,430860010D00A91,2EBC9540FD437B0,76812D24FA5B8A2,9BF0BD7B3042C85,343796828D816C1,2507AE748CF6C75,5EC63B4F5296B23,BD6693038D935E0,D6AE555C1D90756,74CA97EEDC07603,1065F5EA534FDC0,3AC01290900F7B4,799457128844607,4BBE1AEE2EA7482,0D0F267D1CDA8D5,4707F065507DE33,A141F335C0BEAC4,DE13F2355B40987,9072A8A00952DA0,F27233E6E848C22,20A1946BCEDB1C0,9F4C2E962590E84,83BF962C1653240,50AB32B04FD5B56,1A552E143602C35,ED004852DAAD6A7,3ABEF578EB1CF75,390C2219C941E55,A43A5F4ED7D86E0,2EBC9540FD437B0,7084050DA7047F3,9BF0BD7B3042C85,887456145250314,2507AE748CF6C75,D039BC7A75FE8F6,BD6693038D935E0,46CBF7AC0184EA2,74CA97EEDC07603,1065F5EA534FDC0,7C1E4D62C1B8053,94CCC0C83729560,4BBE1AEE2EA7482,0D0F267D1CDA8D5,3A587A168377EC5,7BF3C2DF98A8666,DE13F2355B40987,9072A8A00952DA0,84F7541D57A4325,20A1946BCEDB1C0,90F354161103415,83BF962C1653240,E91A870CF4A2433,1A552E143602C35,082DC80648F5061,3ABEF578EB1CF75,390C2219C941E55,33482B67976A9F1,410E48F61534346,7084050DA7047F3,C5E480304AFE417,8C9C7FA8EBCADD2,A7328D43F6821AB,F0D88CE9BFA7111,9D6D2B389152B0A,1B5F6FBEE8AED98,2DEA4268FD7D1DF,105383313C01750,F3B4374C14E5E89,F4F6A8A18782601,D7311BD41425CAE,DA9DD307EEF2FE0,ADDD208B06E501D,F317F5985C396AF,7726D20E7953C9B,19ABD34BACA070E,3E419AFA457FD07,D19708B5E150608,724520300787F83,FE883D869A2FC07,CA845D7A24223D0,F4F6A8A18782601,C5188DCE39CA66E,E5C0222133943EF,9D411DBFDC2B57C,F317F5985C396AF,461079E3AA45442,2D7A791FC2FCBDF,281427589A63971,06EA6AF4FF17EA0,60A0D75EF863173,FE883D869A2FC07,6536A172DF5A7CB,3FA196575175CFF,E893D9D14482677,E5C0222133943EF,CDA03131CB8D098,0B93455E4000A08,A82497F0A6D6E75,64315CA2C98B835,D5B4F1996490E3E,0A562F7F79F5E70,4E9C6DD0BAC2634,933C612FEE7E74C,52771805F1AD0B2,3FA196575175CFF,F002C83D2260AE7,EBBCF90CE4B80A9,E3E95AA9C1F2B09,AB7A44A17B3ACBB,BAF0EB80DE72353,FF039A70771355F,6E0F346915AB265,0022F6579C7AF36,4E9C6DD0BAC2634,F4E68E22185E411,C33B828549258FE,3F3A05AA30EBC9F,F002C83D2260AE7,36F1520077831E7,DA9DD307EEF2FE0,749D8282D940FA30,115442AB8C57D980,5FBE87E7BDFCFEA1,D35A7A7A4F4FE9E1,09242DA4E4A69480,9692B253524ACA41,44AD8484D9803220,23C2C868541D0391,6D280D2465B624B0,05C5C0A8D4171380,749D8282D940FA30,115442AB8C57D980,5FBE87E7BDFCFEA1,D35A7A7A4F4FE9E1,09242DA4E4A69480,9692B253524ACA41,44AD8484D9803220,23C2C868541D0391,6D280D2465B624B0,05C5C0A8D4171380,749D8282D940FA30,115442AB8C57D980,5FBE87E7BDFCFEA1,D35A7A7A4F4FE9E1,09242DA4E4A69480,9692B253524ACA41,D75A5A7B4F5F69E1,23C2C868541D0391,6D280D2465B624B0,05C5C0A8D4171380,749D8282D940FA30,115442AB8C57D980,5FBE87E7BDFCFEA1,D35A7A7A4F4FE9E1,09242DA4E4A69480,9692B253524ACA41,D75A5A7B4F5F69E1,23C2C868541D0391,6D280D2465B624B0,05C5C0A8D4171380,749D8282D940FA30,115442AB8C57D980,5FBE87E7BDFCFEA1,D35A7A7A4F4FE9E1,09242DA4E4A69480,9692B253524ACA41,D75A5A7B4F5F69E1,23C2C868541D0391,6D280D2465B624B0,05C5C0A8D4171380,749D8282D940FA30,115442AB8C57D980,DC183B126B60EC60,D35A7A7A4F4FE9E1,09242DA4E4A69480,9692B253524ACA41,D75A5A7B4F5F69E1,23C2C868541D0391,6D280D2465B624B0,05C5C0A8D4171380,749D8282D940FA30,B6FFC9ADFAD44743,87CF4258181C35C0,7D7CFF63E3F19CB1,25AFBF779495E291,54E4D29867582B22,FC8EF386C3F1E062,3A2A46E1D8A03A12,76AC7010EF52F220,B3AA23B3C881B0C2,CA8C13E60DE11062,C04AF4CC33C29F73,8EBD30D73A36F043,9A3002386C200B41,036595602C863A91,26BE0061AED12C00,B3FB2906E8CCC4C1,902074D76280C253,F7685540E9920AF0,DE52C30B4B7A6F60,F50F3D14F71488F1,72E4825BEF8B6521,AB326A64AE2B8AC1,B6FFC9ADFAD44743,87CF4258181C35C0,7D7CFF63E3F19CB1,25AFBF779495E291,54E4D29867582B22,FC8EF386C3F1E062,3A2A46E1D8A03A12,76AC7010EF52F220,B3AA23B3C881B0C2,D7251F944F5450F3,C04AF4CC33C29F73,8EBD30D73A36F043,9A3002386C200B41,036595602C863A91,26BE0061AED12C00,B3FB2906E8CCC4C1,902074D76280C253,F7685540E9920AF0,DE52C30B4B7A6F60,E3C2F7A4BFC8A0F2,72E4825BEF8B6521,AB326A64AE2B8AC1,B6FFC9ADFAD44743,87CF4258181C35C0,7D7CFF63E3F19CB1,8254FC890C4ACF52,54E4D29867582B22,FC8EF386C3F1E062,3A2A46E1D8A03A12,76AC7010EF52F220,B3AA23B3C881B0C2,D7251F944F5450F3,C04AF4CC33C29F73,8EBD30D73A36F043,9A3002386C200B41,4D64C27615B904A1,26BE0061AED12C00,B3FB2906E8CCC4C1,902074D76280C253,F7685540E9920AF0,E71D5B67AF5B7BA5,BBC518CDCE615223,D1C02F21770263B0,3ADA4EE9E8E083B3,071289C70C5C4927,8E9350140AFA0A44,02E81C38184300F4,0C9B02B9203275C6,1E98608748FD3A02,7283B39AC9C93F42,0FAA11233C787184,B657490ADAD97C20,627FCD4399CAFC35,67F53CFABDDA14F3,46A8378C399E9216,E9818861A76DE0A1,9B3F1B837EEA9B26,C64417483B519215,EAD871479B602605,7A77C06CF9EA2281,5B7916416D69BB15,BDF0C955F6794261,057B707F149D7FC1,C4F7DBD61393B663,4F3EA9650DBA8AA5,176A53F37C5C45C3,880C54A112EAD796,E154110A87CB7E04,DBD570AA4FEF4D82,ADD880FAA634EBC7,A7513F75AE11C9F1,9E36F1D14AF2D443,81AA5670268483D5,D0DAC4CB43C07C13,FBC6D903EF64CC24,6815255BA1A71C51,A6195C7CAA1FBFF1,FBB6B987DF659F26,F846E554D3203451,2E38162E887FA694,46EE3914295B0764,E9CB663997295CD4,1A4DFE9B48676176,04993BF41017D0E7,AA008DFB8A6E5CF3,833716A22ECEB192,A783191E9E57DF64,E71D5B67AF5B7BA5,BBC518CDCE615223,D1C02F21770263B0,3ADA4EE9E8E083B3,071289C70C5C4927,8E9350140AFA0A44,02E81C38184300F4,0C9B02B9203275C6,1E98608748FD3A02,176A53F37C5C45C3,0FAA11233C787184,B657490ADAD97C20,627FCD4399CAFC35,67F53CFABDDA14F3,46A8378C399E9216,E9818861A76DE0A1,F3339F4E62C75A7B,5E908D6D7F4F1A10,83882D473ECFE64C,D76A40215DB2EAEB,D93B2126C0D28C59,524510E1BEF9DD1A,25601D0B94A1762B,83D6FC7EE5BA74F6,14073890CDDC0B02,F3339F4E62C75A7B,1DCE35F5F1D68C3B,B0AA1DBDECAD9F60,2DE5EB2AD24722A6,D93B2126C0D28C59,E32C4AD75C6BA4CA,77EA41EF7C614FBF,36CE494E2FE8692B,A1D06501B0BDA155,5E62CB3D98B14DAE,669FDE72C3612733,B0AA1DBDECAD9F60,31CA9B2C802DBF9F,3AE22D93F6478A94,964EE842D3F7F944,77EA41EF7C614FBF,727E4B6F7E047D05,A1D06501B0BDA155,323DF6B8BADBCB11,D4EA1CFBE67578DF,01B5AED234F15332,3B2341BABC5C3B1F,4518C91903A521A5,964EE842D3F7F944,1192E1616471ABB3,727E4B6F7E047D05,667E0E7702D0D18E,ADEBD7CC117423E6,C078B309CC2DE6E1,85B4407FD3C3D0CD,3B2341BABC5C3B1F,F5CD759FE12A58FE,4AA2A199C2A6539F,E6BC85BCAF0B304F,376B7452676C4CA4,C70F767431F6A75D,ADEBD7CC117423E6,4A2F6AF3C85556AB,314AABE6A40E0D21,5BAAE764F09C1C18,F5CD759FE12A58FE,EF9B8A99006897FB,E6BC85BCAF0B304F,77D78407E9428F84,D1E20EAC49A59FD4,C02EE7E2379EB7E5,0C7B9A6B2605C587,867904CE66D32074,5BAAE764F09C1C18,DB1420649ABE3DDA,EF9B8A99006897FB,2AF8022F7D3F209F,5E4BE60582F38D1B,5228D2691BA08A29,CE09CC07391BF6ED,B26F547DD64D97C11,34C5781BD6479F620,A24844B89B7163D00,96FDBB3843B7F1EA1,D87E7CD36259D07D1,658F52C1B8AE1E130,CEEBFD21060FC4A61,6188668CAE82C1000,222F9C7885FC91E11,B04B0D78CB0D29E10,1A6B1D036BFD60241,FB01F81FF1A447640,95C5A8DE637775630,007354BB235D85C81,6F52E722A569689E0,B7A931D0C0B624431,15101FFA4D30E9FB0,6451AABD91F563FA0,560D191E72F45F620,713DECD8FDD433691,1AAE3D14468A38741,08BE0CF906DA35FD1,086227B81C6903C41,85CA2D1107CB6C620,199CBA0073E2122C0,F6DADA2FDE3BCFBA0,ECB6643FBA3A5BDE1,2ADFEDE4AF4FD0AD0,61C07F74B243E6F10,B26F547DD64D97C11,A75525B5B6455ACA0,A24844B89B7163D00,B9F35164E79F648D1,D87E7CD36259D07D1,658F52C1B8AE1E130,CEEBFD21060FC4A61,838448DB20E239610,222F9C7885FC91E11,ACDA0B099B1B072E0,E27DCB259705D6B81,FB01F81FF1A447640,121518A865549DB80,007354BB235D85C81,6F52E722A569689E0,B7A931D0C0B624431,300081DAEF9005410,6451AABD91F563FA0,889985DC36D66B5D0,713DECD8FDD433691,1AAE3D14468A38741,08BE0CF906DA35FD1,F3384E78C7D0E9F91,85CA2D1107CB6C620,E14C29DE8451F9610,007F25E016FD3A991,ECB6643FBA3A5BDE1,2ADFEDE4AF4FD0AD0,2209BB61980466A10,B26F547DD64D97C11,A75525B5B6455ACA0,8E0D293D2504D5F60,B9F35164E79F648D1,85C2AA06313BAE220,658F52C1B8AE1E130,CEEBFD21060FC4A61,4268B5989359F1272,EA04DA65258D9E693,8DAF8F1A90686ED03,562508EF9B99EEE51,37F738859C74124B0,56F7F3E60AD27D2B1,DC6EBAFD6FD286BC0,54C4020AB0137B223,9F831FC8E4E6E9012,B2CD010038AF24811,86EA98DE2636F38F2,FFC3462E8C9905E13,32DD639A292785CF3,4B7269213AF963AB0,1BDB47C2181C975D1,5C795033625816FE1,73E8F612A12E1E7D1,8EB9BC2C3A3082851,2342DAAE66116B4D2,3C1A01A429CD7FDE0,EA04DA65258D9E693,E9A30F1021D31FE83,CA49074CAE33966F3,9FD6A08836C3ED091,CA2B03452011E2A53,0DD12C4EB9BAA89E2,261C518B72E839CD2,5426CE8E5E3060F81,B2CD010038AF24811,4D381A70EF40EAB42,C31DCF63185230253,E50F73F8FF0C992E2,A4CC75C2F2D6929E3,D8360F1092EEAAA63,E4E1123FE8E14FAE2,73E8F612A12E1E7D1,7B5296FA30CF26670,2342DAAE66116B4D2,496612C7EFBCEABE0,E6C9214A8B7C83B91,A8EDCD2167DF2F4E2,F037D745EF07CAB20,072AF5C8E155934F2,CA2B03452011E2A53,3A5DF8126606CFD72,600603B0D16568EC0,39A29EA5E0B1E7483,692C5DB52BC545B41,56F7F3E60AD27D2B1,EBFCDF67669B643D3,E50F73F8FF0C992E2,995497BFCF11061C1,D8360F1092EEAAA63,F28A0BAEF3726BB73,BC36132F47EDDA540,5DB5263E55FDBFAE0,52D7EC4E19EC11391,1023C693C59773101,A32380B64B579BCD0,A8EDCD2167DF2F4E2,30ABE948DBF5E00C0,6C6AE5FBD1DACF263,4268B5989359F1272,EA04DA65258D9E693,8DAF8F1A90686ED03,39A29EA5E0B1E7483,9D632D42E5072AF50,0052EACC694AF2533,6C2B7460129EB5562,C9ED2D049213F5877,E7106EE9B3E2D6902,4ABE8558E933902D6,75E994D2A651DBB14,8E9FF6FAB98DE24C4,5D0E79917619AEFD2,24B4C433550B722A6,904BB113C1933E7B0,4CB45F82B24BF7164,31F6C6DE5E7FEF905";
	res[2] = "02F0BAA96D55C2616,227F9734F73BA4111,34C57FCFFA7AA9497,204F168C60D416483,1A6FB3D50838C90D1,5A383FFE9664DC763,4801B784885392743,0CF095A7D506A3655,9D3CF1873505FFC53,C9C794742BCD14DC7,0F0C16EEC90347EC1,A89F6CB4A7F3440F7,8B83004B5B88C7F64,7664B2DF5C2B1F633,4ABE8558E933902D6,1B18E9640CCEECED3,443434FF4D0CF4423,B221A77D3C6EA9593,83D17BA50BFB90FA5,F0174530C90E8D1B0,DA9A33966E1D3D0D7,846CE79CDEA945223,AD1C8E10F66A75862,227F9734F73BA4111,D2FEC814615B0F0A7,DF50A6A1739DECEC2,8697988E9029E3705,B8196367F499ED5C3,6E25785B457C566C0,0B2D9C9AFCB865BD0,706226116174AC330,B84016F7C8A6DB041,F9BF4DE341FA48F44,5F8F484EF156DACF5,AD96822D7A1702E55,1B89A4E52F998DB67,9D632D42E5072AF50,0052EACC694AF2533,9D40AE23A6CC7BFD0,C9ED2D049213F5877,E7106EE9B3E2D6902,D400EA2815914F610,75E994D2A651DBB14,F6E6B6CFDE0ED9737,5D0E79917619AEFD2,24B4C433550B722A6,904BB113C1933E7B0,DF50A6A1739DECEC2,31F6C6DE5E7FEF905,B8196367F499ED5C3,E3CF60A18C3C46AA4,34C57FCFFA7AA9497,D124CCCFD486D8E31,1A6FB3D50838C90D1,E14E78FB88C5FDE02,6E8DF432F5353C27C,906F1F106EB17C40B,180CE3F273ECBC040,E5EFE84CCBA04FE2F,A99004CFAA92F3DC4,17DFB4EA4FA3C29BE,2B8FC3AECCD2FF85C,6D19BB6FD548EDAE8,E2B3B96688FE0A69D,D403B7A31FDCCE628,BA508068C65D014D2,952672780967D9C21,4C86B3816E05DE364,88E04FD12190F2447,6F33F017D2F3F3BF9,DA9C4A9364623A6D4,C31A1771404B50E90,AECC77EA96CC01576,0DE1076E04BBFF96F,54480D4B02DE24322,109D010E73790808C,9F2808F5314FD3D71,B33D1786A2048CD99,FF42FB05C33630E72,92857C6376051D41C,D9B21AF75BD9BBEC5,D9B21AF75BE9BBEC5,33BACD56E3F524895,B764FDCCCE6D27C33,0E6EF3C23475F3073,A13F3505A6CF34D89,E42F1C6BA39F43729,9DBE0A8719C637DE5,677617EDB1E69FAB3,C8C191263F2BBA74E,440998401DD7A1228,391D9CEFD898B28C8,E14E78FB88C5FDE02,6E8DF432F5353C27C,906F1F106EB17C40B,180CE3F273ECBC040,E5EFE84CCBA04FE2F,A99004CFAA92F3DC4,17DFB4EA4FA3C29BE,2B8FC3AECCD2FF85C,6D19BB6FD548EDAE8,E2B3B96688FE0A69D,D403B7A31FDCCE628,BA508068C65D014D2,952672780967D9C21,4C86B3816E05DE364,88E04FD12190F2447,6F33F017D2F3F3BF9,DA9C4A9364623A6D4,C31A1771404B50E90,AECC77EA96CC01576,0DE1076E04BBFF96F,54480D4B02DE24322,109D010E73790808C,9F2808F5314FD3D71,B33D1786A2048CD99,FF42FB05C33630E72,92857C6376051D41C,D9B21AF75BD9BBEC5,D9B21AF75BE9BBEC5,33BACD56E3F524895,B764FDCCCE6D27C33,E17AB2DF0563D06A91,81741BC725CF405A30,9D61454C503A9254B0,74BE33DF59FD7D2FF1,5ADAA5F2734E013E61,5DD13B5950D7FC2C20,7987934144E8643501,5E49FCFD76F7FCB6C0,E8C95ADF246EC86740,1EBD949EDABBF01FD0,496CA32F2A8E1335F0,49263AD8AD8956B271,6EBAF017B6B7EC3991,3CF22CCE6BF3120BD1,9EAB17F245B456C6B1,ED60E4382C582861F0,137771865FA1D98F11,538761FCF641B6A701,461380D113FCB33EE1,CE85002E049887E0A0,650640CE0B95282661,3221A908C8A58C0190,AC60D8A3849EE24350,4618D07003776A28A0,1720B4FFC4BF559610,FEC01186F17EF67700,5D0E64394690293101,4EC16A700A5FA521E0,CB3978C51AC563EB30,98F3A1015466145C51,F7F5AA7F475E0DED30,EAA99EA735627FF770,6264637017C029B0F0,7C9FCAC8663932AA01,537ED9BEE64EF3BA31,21E726ECAD8F9E9351,C4ACF06330D542F090,F6086040D2D4B4F1A0,DB2B2D66704906F091,BCDDBCD54A13EECA20,734E38DC6A46E9B2E1,87E5F49D0414FFD390,972B8EC76BB503C391,CE87F1B521B5656201,8FE6C44E14F6AD4511,E17AB2DF0563D06A91,81741BC725CF405A30,9D61454C503A9254B0,B0FA290AD701ABDC71,5ADAA5F2734E013E61,5DD13B5950D7FC2C20,5F6B7AAE71584123B1,5E49FCFD76F7FCB6C0,411AA86F9E48983901,1EBD949EDABBF01FD0,496CA32F2A8E1335F0,49263AD8AD8956B271,97722E4064509B4C51,3CF22CCE6BF3120BD1,9EAB17F245B456C6B1,ED60E4382C582861F0,137771865FA1D98F11,74BE33DF59FD7D2FF1,461380D113FCB33EE1,CE85002E049887E0A0,650640CE0B95282661,C67E7340321FFDF931,AC60D8A3849EE24350,B740E8D7765E1E4280,00B255A2175B110891,748D756799D52934B3,721368330CA3A83CB1,9E9AC58790F0EE2CB1,B8A75CD675814B3423,6513D484A227D7DC81,EA7D59BE9862A41DB2,C805F49D8F59490703,E3E54E155F8F5A9273,4148EA3FAF3860C5E0,39BEBA7ACF1B979C22,D5C30A86452D69E750,7CE0163292085333B0,840EF40B8EEF944442,86D1EC998476082DA1,BB1E85A732CE31B882,71601FD1AAD0CED530,9F2A24EC28C876C2D1,084DF6A8EE147567D3,A5DF5092AAB6D4BAA2,2F1BC3B9BEE6EF9F41,029E832B8DD3920AB3,6F2340116D3E5BB151,FC7AA7AB88DE7A7D40,21CE2F995F7BE695E2,3CDAAD003765DD7D91,3DF5A6DB329C65FE83,F381F356661B63F2B1,768225B04E96263630,39BEBA7ACF1B979C22,494C800D173CA2A7A3,B0770EC052D0E25883,9C0B63881B089E45C0,C197783BBDF6F3EEC3,27D698DE1CA4A298A3,EDC802AB84BA5DF511,E9C969131A68E597E0,FBEC9540509FB7F6F3,D27EE51158EE370A82,10D176FD4718850ED0,029E832B8DD3920AB3,245E04289EAD087F23,3E37483504DE7B1963,FC5418BDA328901893,E1409A240B36ADF0E0,4B9F4E8E5E9C00CB72,29CDB557465AECF4A3,ACCE6FB16EB7A93022,5E0C45F8DDB1662473,869C3E294EB3234DB2,06900B20064FA70BC1,2DCEF88C80C9499593,C197783BBDF6F3EEC3,C5960C5C9A32B8EAF2,EDC802AB84BA5DF511,31E043A0D9791D90C1,B0C58EBB5B3BB833D2,EC07548049B52D7332,3B89977E079BC8F5B1,8A070C4B8CB63F2543,ACC78B489FCEA550E3,00B255A2175B110891,748D756799D52934B3,04D7459EA1D6546C52,9E9AC58790F0EE2CB1,B8A75CD675814B3423,ACCE6FB16EB7A93022,EA7D59BE9862A41DB2,869C3E294EB3234DB2,E3E54E155F8F5A9273,";
	
	vector<string> Arr;
	vector<char> split_c(1, ',');
	for (int i = 0; i < 3; i++)
	{
		vector<string> temp = split(res[i], split_c);
		for (int j = 0; j < temp.size(); j++)
			Arr.push_back(Base16ToBase2(temp[j]));
	}
	
	{
		int a = 1;
		int b = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			Arr[i] = Arr[i].substr(Arr[i].length() - a, a);
			b++;
			if (a == b)
			{
				b = 0;
				a++;
			}
		}
	}

	for (int i = 1; i <= 70; i++)
	{
		vector<vector<int>> temp(i, vector<int>(i, 0));
		B_Matrix[i] = temp;
		vector<vector<int>> temp2(i, vector<int>(i, 0));
		A_Matrix[i] = temp2;
	}

	{
		int a = 1;
		int b = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			for (int j = 0; j < Arr[i].length(); j++)
				B_Matrix[a][b][j] = (Arr[i][j] - '0');
			b++;
			if (a == b)
			{
				b = 0;
				a++;
			}
		}
	}

	result += "a_i = a_{i-1} . a_{i-2}\n";
	result += "\n";
	result += "a_1 = 0\n";
	result += "\n";
	result += "a_2 = 0 1\n";
	result += "\n";

	string a = "0";
	string b = "01";
	for (int i = 3; i <= 15; i++)
	{
		string c = b;
		c += a;
		int spaceV = 5 + (int)log10(i);
		string spaceS = "";
		for (int j = 0; j < spaceV; j++)
			spaceS += " ";
		for (int j = 0; j < c.length(); j++)
		{
			if (j == 0)
			{
				result += "a_";
				result += to_string(i);
				result += " =";
			}
			else if(j % 40 == 0)
				result += spaceS;
			result += " ";
			result += c[j];
			if (j % 40 == 39 || j == c.length() - 1)
			{
				if (j % 40 == 39)
					result += " ";
				result += "\n";
			}
		}

		//result += "\n";
		result += "\n";
		a = b;
		b = c;
	}
	for (int i = 16; i <= 20; i++)
	{
		string c = b;
		c += a;
		a = b;
		b = c;
	}

	{
		for (int j = 1; j <= 70; j++)
			for (int i = 0; i < j * j; i++)
				A_Matrix[j][i / j][i % j] = b[i] - '0';

	}

	result += "\n";
	result += "(A_i)^n = B_i (mod 2)\n";
	result += "\n";

	for (int i = 1; i <= 70; i++)
	{
		string temp = "";
		for (int j = 0; j < i; j++)
		{
			if (j == i / 2)
			{
				temp += "A_";
				temp += to_string(i);
				temp += " =";
			}
			else
			{
				temp += "   ";
				if (i / 10 >= 1)
					temp += " ";
				temp += "  ";
			}
			for (int k = 0; k < i; k++)
			{
				temp += " ";
				temp += (char)(A_Matrix[i][j][k] + '0');
			}
			temp += "   ";
			if (j == i / 2)
			{
				temp += "B_";
				temp += to_string(i);
				temp += " =";
			}
			else
			{
				temp += "   ";
				if (i / 10 >= 1)
					temp += " ";
				temp += "  ";
			}
			for (int k = 0; k < i; k++)
			{
				temp += " ";
				temp += (char)(B_Matrix[i][j][k] + '0');
			}
			temp += "\n";
		}
		temp += "\n";
		result += temp;
	}

	cout << result;

}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int G;
	cin >> G;
	if(G == 0)
		Fun0();
	else if (G == 1)
		Fun1();
	else if (G == 2)
		Fun2();
	else if (G == 3)
		Fun3();
	else if (G == 4)
		Fun4();
	else if (G == 5)
		Fun5();
	else if (G == 6)
		Fun6();
	else if (G == 7)
		Fun7();
	else if (G == 8)
		Fun8();
	else if (G == 9)
		Fun9();
	else if (G == 10)
		Fun10();
}