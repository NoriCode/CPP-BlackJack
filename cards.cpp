#include "cards.h"


#include "cards.h"

int cards::whoAmI() {
    printf("%s,%s", getSymbol().c_str(), getnumber().c_str());
    return 0;
}
