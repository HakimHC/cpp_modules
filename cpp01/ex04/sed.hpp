#ifndef SED_H
# define SED_H

# include <iostream>

typedef std::string str;

str replace(str original, str src, str dest);
void sed(str path, str src, str dest);

#endif
