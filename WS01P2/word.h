#ifndef SDDS_WORD_H
#define SDDS_WORD_H
namespace sdds {
   struct Definition {
      char m_type[64];
      char m_definition[1024];
   };
   struct Word {
      char m_word[64];
      int m_tdCount;
      Definition defs[8];
   };

}
#endif