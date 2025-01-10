folder_name=$1

replace_text() {
  local file="$1"
  local old_text="$2"
  local new_text="$3"
  sed -i "s/$old_text/$new_text/g" "$file"
}


mkdir $folder_name
cd $folder_name
cp ../CMakeLists.txt  .

replace_text CMakeLists.txt "placeholder" $folder_name

mkdir include
mkdir src
mkdir build

touch include/functions.h

touch src/main.c
touch src/functions.c
