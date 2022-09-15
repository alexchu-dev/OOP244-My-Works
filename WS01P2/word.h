#ifndef SDDS_WORD_H
#define SDDS_WORD_H
namespace sdds {
   const int MAX_WORD_LENGTH = 20;
   const int MAX_DEF_LENGTH = 60;
   struct Word {
      char m_word[MAX_WORD_LENGTH+1];
      char m_type[MAX_WORD_LENGTH+1];
      char m_definition[MAX_DEF_LENGTH+1];
   };
}
#endif