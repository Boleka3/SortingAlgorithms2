class item
{
String itemname;
string category;
Int price;
public:
item(string, string, int);
bool operator<(const item&);
void print();
};
