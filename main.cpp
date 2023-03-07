#include "zpipe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  Zpipe zpipe;
  int ret;
  FILE *filename, *zipped;
  std::string s;

  if (argc == 2)
  {
    filename = fopen(argv[1], "rb");
    s = argv[1];
    s = s + ".Z";
    zipped = fopen(&s[0], "w");
    ret = zpipe.def(filename, zipped, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK)
    {
      zpipe.zerr(ret);
    }
    else
    {
      std::cout << "Compression Level is: 6 (Default)" << std::endl;
      std::fseek(filename, 0L, SEEK_END);
      std::cout << "Old File Size is: " << std::ftell(filename) << " bytes" << std::endl;
      std::fseek(zipped, 0L, SEEK_END);
      std::cout << "New File Size is: " << std::ftell(zipped) << " bytes" << std::endl;
      std::cout << "Compression Ratio is: " << (std::ftell(filename) / std::ftell(zipped)) << std::endl;
    }
    return ret;
  }
  else if (argc == 3 && strcmp(argv[1], "-d") == 0)
  {
    zipped = fopen(argv[2], "rb");
    s = argv[2];
    s = s.substr(0, s.length() - 2);
    filename = fopen(&s[0], "w");
    ret = zpipe.inf(zipped, filename);
    if (ret != Z_OK)
    {
      zpipe.zerr(ret);
    }
    return ret;
  }
  else
  {
    zpipe.usage(argv);
    return 1;
  }
}
