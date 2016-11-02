from PIL import Image

def indSum( x ) :
	sig = 0;
	for i in range( 3 ):
		if( x[i] ):
			sig += i+1;
			
	return sig;

def getRGB( x ):
	sig = indSum( x );
	if( sig == 0 ):
		return "Blk";
	elif( sig == 6 ):
		return "W";
	elif( sig == 1):
		return "R";
	elif( sig == 2 ):
		return "G";
	elif( sig == 3 ):
		return "Blu";


newImg = "new.png";

img = Image.open('simg.png');
img.show();
arr = img.load();

( x, y ) = img.size;
#x - width, y - height
print( "the image is " + str( x ) + " by " + str( y ) + "." );
for i in range ( x ):
	for j in range( y ):
		print( getRGB( arr[j,i] ) , end=' ' );
	print( "" );	
