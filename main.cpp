#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <map>
using namespace std;

map<string, double> table = {
        {   "H",	1.00	},
        {	"He",	4.00	},
        {	"Li",	7.00	},
        {	"Be",	9.00	},
        {	"B",	11.00	},
        {	"C",	12.00	},
        {	"N",	14.00	},
        {	"O",	16.00	},
        {	"F",	19.00	},
        {	"Ne",	20.00	},
        {	"Na",	23.00	},
        {	"Mg",	24.00	},
        {	"Al",	27.00	},
        {	"Si",	28.00	},
        {	"P",	31.00	},
        {	"S",	32.00	},
        {	"Cl",	35.00	},
        {	"Ar",	40.00	},
        {	"K",	39.00	},
        {	"Ca",	40.00	},
        {	"Sc",	45.00	},
        {	"Ti",	48.00	},
        {	"V",	51.00	},
        {	"Cr",	52.00	},
        {	"Mn",	55.00	},
        {	"Fe",	56.00	},
        {	"Co",	59.00	},
        {	"Ni",	59.00	},
        {	"Cu",	64.00	},
        {	"Zn",	65.00	},
        {	"Ga",	70.00	},
        {	"Ge",	73.00	},
        {	"As",	75.00	},
        {	"Se",	79.00	},
        {	"Br",	80.00	},
        {	"Kr",	84.00	},
        {	"Rb",	85.00	},
        {	"Sr",	88.00	},
        {	"Y",	89.00	},
        {	"Zr",	91.00	},
        {	"Nb",	93.00	},
        {	"Mo",	96.00	},
        {	"Tc",	97.00	},
        {	"Ru",	101.00	},
        {	"Rh",	103.00	},
        {	"Pd",	106.00	},
        {	"Ag",	108.00	},
        {	"Cd",	112.00	},
        {	"In",	115.00	},
        {	"Sn",	119.00	},
        {	"Sb",	122.00	},
        {	"Te",	128.00	},
        {	"I",	127.00	},
        {	"Xe",	131.00	},
        {	"Cs",	133.00	},
        {	"Ba",	137.00	},
        {	"La",	139.00	},
        {	"Ce",	140.00	},
        {	"Pr",	141.00	},
        {	"Nd",	144.00	},
        {	"Pm",	145.00	},
        {	"Sm",	150.00	},
        {	"Eu",	152.00	},
        {	"Gd",	157.00	},
        {	"Tb",	159.00	},
        {	"Dy",	163.00	},
        {	"Ho",	165.00	},
        {	"Er",	167.00	},
        {	"Tm",	169.00	},
        {	"Yb",	173.00	},
        {	"Lu",	175.00	},
        {	"Hf",	178.00	},
        {	"Ta",	181.00	},
        {	"W",	184.00	},
        {	"Re",	186.00	},
        {	"Os",	190.00	},
        {	"Ir",	192.00	},
        {	"Pt",	195.00	},
        {	"Au",	197.00	},
        {	"Hg",	201.00	},
        {	"Tl",	204.00	},
        {	"Pb",	207.00	},
        {	"Bi",	209.00	},
        {	"Po",	209.00	},
        {	"At",	210.00	},
        {	"Rn",	222.00	},
        {	"Fr",	223.00	},
        {	"Ra",	226.00	},
        {	"Ac",	227.00	},
        {	"Th",	232.00	},
        {	"Pa",	231.00	},
        {	"U",	238.00	},
        {	"Np",	237.00	},
        {	"Pu",	244.00	},
        {	"Am",	243.00	},
        {	"Cm",	247.00	},
        {	"Bk",	247.00	},
        {	"Cf",	251.00	},
        {	"Es",	252.00	},
        {	"Fm",	257.00	},
        {	"Md",	258.00	},
        {	"No",	259.00	},
        {	"Lr",	262.00	},
        {	"Rf",	267.00	},
        {	"Db",	270.00	},
        {	"Sg",	269.00	},
        {	"Bh",	270.00	},
        {	"Hs",	270.00	},
        {	"Mt",	278.00	},
        {	"Ds",	281.00	},
        {	"Rg",	281.00	},
        {	"Cn",	285.00	},
        {	"Nh",	286.00	},
        {	"Fl",	289.00	},
        {	"Mc",	289.00	},
        {	"Lv",	293.00	},
        {	"Ts",	293.00	},
        {	"Og",	294.00	}
};

class MOLE{
public:
    string name;
    string formula;
    double mass;
    MOLE(const string &n, const string &f, double m){
        name = n;
        formula = f;
        if (m == 0)
            mass = calMass(f);
        else
            mass = m;
    }
private:
    double calMass(string f){
        stack<double> s;
        double sum = 0;
        size_t i = 0;
        do {
            switch (f.at(i)){
                case 'A'...'Z':
                    if (i+1 < f.size() && f.at(i+1) >= 'a' && f.at(i+1) <= 'z') {
                        s.push(table[f.substr(i, 2)]);
                        i++;
                    } else
                        s.push(table[f.substr(i, 1)]);
                    i++;
                    break;
                case '(':
                case '[':
                    s.push(-1);
                    i++;
                    break;
                case ')':
                case ']': {
                    double a = 0;
                    while (s.top() != -1) {
                        a += s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(a);
                    i++;
                    break;
                }
                default: {//'0' ... '9'
                    size_t j = 0;
                    double b = s.top();
                    s.pop();
                    s.push(b * stoi(f.substr(i), &j));
                    i += j;
                }
            }
        } while (i < f.size());

        while (!s.empty()){
            sum += s.top();
            s.pop();
        }

        return sum;
    }
};

class MOLES{
private:
    vector<MOLE> v;
    int t;
public:
    MOLES() : t(0) {};
    void push_back(const MOLE &mole){
        v.push_back(mole);
    }
    int size(){
        return (int)v.size();
    }
    void qsort(int left, int right){
        if (left < right){
            int i = left, j = right + 1;
            double pivot = v[left].mass;

            do{
                do i++; while (i < v.size() && v[i].mass < pivot);
                do j--; while (j < v.size() && v[j].mass > pivot);
                if (i < j) {
                    iter_swap(&v[i], &v[j]);
                    t++;
                }
            } while (i < j);

            if (left != j) {
                iter_swap(&v[left], &v[j]);
                t++;
            }
            qsort(left, j - 1);
            qsort(j + 1, right);
        }
    }

    void print(){
        for (auto &i : v) {
            cout << left << setw(40) << i.name;
            cout << left << setw(25) << i.formula;
            cout << right << setw(10) << fixed << setprecision(2) << i.mass;
            cout << endl;
        }
        cout << t << " swaps during qsort" << endl;
    }
};

int main() {

    int n;
    cin >> n;
    cout << n << endl;

    while (n-- > 0){
        MOLES moles;
        int m;
        cin >> m;
        cout << m << endl;

        while (m-- > 0){
            string na, fo;
            double ma;
            cin >> na;
            cin >> fo;
            cin >> ma;

            MOLE temp(na, fo, ma);
            moles.push_back(temp);
        }

        moles.qsort(0, moles.size() - 1);
        moles.print();
    }

    return 0;
}