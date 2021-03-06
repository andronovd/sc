#gal spot class
class galSpot:
	row = 0
	col = 0
	block = 0
	iD = 0
	name = 0
	
	def __init__( self ):
		#print( "creating galSpot" );
		row = 0
		col = 0
		block = 0
		iD = 0
		name = 0
		
	def __init__( self, block, col, ID, name ,row ):
		#print( "creating galSpot" );
		self.block = block;
		self.col = col;
		self.iD = ID;
		self.name = name;
		self.row = row;

#open the file
#fname = input("Enter file name:" );
f = open( "test.gal", "r" );
data = []
colnames = [];
mapp = {};


#look through the file and find the first instance of "Block"
i = 0;
j = 0;
for line in f:
	data = line.split();
	i+=1;
	#print( data[0] );
	if( data[0].strip( '"' ) == "Block" ):
		break;


#create map
for x in data:
	mapp[x] = j;
	j+=1;


#sort the data
data.sort();
#print( "Sorted headings: ", data );


#generate the translation array
translate = [];
for x in data:
	translate.append( mapp[x] );

#print( "Translation array: ", translate );


#continue reading through the file
spots = [];
for line in f:
	data = line.split();
	s = galSpot( data[translate[0]], data[translate[1]], data[translate[2]], data[translate[3]], data[translate[4]] )
	spots.append( s );

f.close()
print( "Completed gal file analysis" ); 
print( "Results" );

i = 0;
for x in spots:
	print( "%i, %s, %s, %s, %s, %s" % ( i, x.block, x.row, x.col, x.iD, x.name ) ); 
