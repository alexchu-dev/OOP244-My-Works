#ifndef SDDS_WORD_H
#define SDDS_WORD_H
#define MAX_DEF 8
namespace sdds {
   struct TypeDef {
      char m_type[64];
      char m_definition[1024];
   };
   struct Word {
      char m_word[64];
      int m_tdCount;
      TypeDef defs[MAX_DEF];
   };

}
#endif