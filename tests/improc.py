from PIL import Image
newImg = "new.png";

img = Image.open('simg.png');
img.show();
arr = img.load();

( x, y ) = img.size;
print( "the image is " + str( x ) + " by " + str( y ) + "." );
for i in range ( x ):
	for j in range( y ):
		print( arr[i, j], end='' );
	print( "" );	
