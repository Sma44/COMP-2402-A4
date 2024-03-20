#include <iostream>
using namespace std;
#include <string>
#include "Escape.h"

// snorcs can't climb higher than bottom 7th row

Escape::Escape()
{
  const char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "-             --        -",
      "-                      --",
      "-       --              -",
      "                  --    -",
      "--       -              -",
      "---                    --",
      "---       --          ---",
      "--                     --",
      "-            --        --",
      "---               --     ",
      "--        --    ---    --",
      "--  --                  -",
      "--        --       -     ",
      "--                  -    ",
      "--     --         --    -",
      "---                    --",
      "--       ---    --      -",
      "--                     --",
      "-------------------------"
  };

}



