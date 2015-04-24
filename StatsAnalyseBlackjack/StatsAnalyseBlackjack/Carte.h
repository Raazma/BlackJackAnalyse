#include <vector>
using namespace std;

class Carte
{
public:
   vector<int> Value_;
   bool Piger_;
 
   int getValue(int index = 0);
   bool piger();
   void reinitialize();

   Carte(vector<int> value);
   ~Carte();
};
