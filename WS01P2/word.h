#ifndef SDDS_WORD_H
#define SDDS_WORD_H
namespace sdds {
   const int MAX_WORD_LENGTH = 64;
   const int MAX_DEF_LENGTH = 1024;
   const int MAX_WORD_DEF = 8;
   struct Definition {
      char m_type[MAX_WORD_LENGTH + 1];
      char m_definition[MAX_DEF_LENGTH + 1];
   };
   struct Word {
      char m_word[MAX_WORD_LENGTH+1];
      Definition defs[8];
   };
}
#endif