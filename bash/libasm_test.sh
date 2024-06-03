#!/bin/bash

# create directory

if [ ! -d ./lib ]; then
  mkdir lib
fi

if [ ! -d ./file ]; then
  mkdir file
fi

if [ ! -d ./file/read ]; then
  mkdir file/read
fi

if [ ! -d ./file/write ]; then
  mkdir file/write
fi

# create file

echo -n "abcdefghijklmnopqrstuvwxyz" > file/read/alphabet.txt
echo -en "first line\n| second line\n| third line\nabcdhrhrhfr\n4545876445343\n\$\$\$\$\$\$\$\$\$\$\nfrfuhfhufhuf\n$$ $$ $$\n" > file/read/with_nl.txt

echo -e "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus blandit dictum nisl facilisis convallis.\n\
Pellentesque eu sodales augue, pellentesque condimentum libero. Nulla non vulputate urna. Morbi accumsan pretium ornare.\n\
Aliquam eget neque ullamcorper purus varius pretium. Cras suscipit euismod justo, at euismod libero egestas sed.\n\
Suspendisse potenti. In ac lacus lectus. Nulla volutpat, augue ut ultrices sodales, dui enim gravida justo, ac cursus metus lacus quis ligula.\n\
Cras at semper lacus. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.\n\
In tincidunt nibh eu mi consectetur dignissim. Nullam malesuada odio et ex accumsan, eget sagittis nunc feugiat.\n\
Vestibulum nec neque lectus. Ut ullamcorper ex eget lorem vestibulum, sed commodo risus placerat.\n\
Phasellus sollicitudin vitae purus ut pulvinar. Sed eget massa sapien. Nullam a efficitur eros.\n\
Aliquam rhoncus magna at condimentum faucibus. Aliquam erat volutpat.\n\
Aenean maximus hendrerit eros, nec condimentum urna ultricies et.\n\
Curabitur hendrerit, purus in posuere tristique, augue purus elementum felis, id sagittis erat lectus ut quam.\n\
Donec dignissim libero ac fermentum hendrerit. Donec blandit pulvinar nulla nec suscipit. Phasellus finibus dictum leo vel sagittis.\n\
Morbi a risus condimentum, lacinia nisl quis, blandit purus. Vestibulum dignissim leo non augue cursus rhoncus.\n\
Etiam purus odio, lacinia vitae orci sit amet, hendrerit cursus est. Vivamus interdum fermentum aliquet.\n\
In hac habitasse platea dictumst. Curabitur laoreet iaculis lorem in suscipit. Donec magna turpis, pulvinar ut consequat id, imperdiet quis leo.\n\
Ut lobortis, felis varius accumsan fringilla, justo purus sodales leo, vitae pellentesque lacus erat et dui." > file/read/little_lorem.txt

touch file/write/std_write.txt file/write/ft_write.txt file/read/empty.txt