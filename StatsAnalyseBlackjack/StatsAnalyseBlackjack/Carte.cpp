#include "Carte.h"


Carte::Carte(vector<int> value) : Value_(value), Piger_(false)
{
}

Carte::~Carte()
{
}

bool Carte::piger()
{
   return Piger_ ? Piger_ : !(Piger_ = true);
}

void Carte::reinitialize()
{
   Piger_ = false;
}

int Carte::getValue(int index)
{

   if (index >= Value_.size())
   {
      return Value_.back();
   }
   else if (index <= 0)
   {
      return Value_.front();
   }
   else
   {
      return Value_.at(index);
   }
}