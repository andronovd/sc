from PIL import Image
newImg = "new.png";

img = Image.open('bh.png');
arr = img.load();

( x, y ) = arr.size();
print( x, y );

new_arr = []
