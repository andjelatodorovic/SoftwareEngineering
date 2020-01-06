struct Trojka uredjenje {
bool operator() (const Trojka& ls , const Trojka& ds) const{
return ((ls.a < ds.a) || ((ls.a == ds.a)&&(ls.b < ds.b)) ||
((ls.a == ds.a)&&(ls.b==ds.b)&&(ls.c < ds.c)) );
}
 };
set<Trojka , Trojka uredjenje> s ;