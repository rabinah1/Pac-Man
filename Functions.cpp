#include <Functions.hpp>

#define V 72

// Find and return the vertex (not in shortest path tree), whose distance from the source is smallest.
// dist[v] = shortest distance from src to v.
int minDistance(int dist[], bool sptSet[])
{
  int min = INT_MAX;
  int min_index = 0;

  for (int v = 0; v < V; v++)
    {
      if(sptSet[v] == false && dist[v] <= min)
	{
	  min = dist[v], min_index = v;
	}
    }
  return min_index;
}

void printSolution(int dist[], int n)
{
  printf("Vertex    Distance from Source\n");
  for(int i = 0; i < V; i++)
    {
      printf("%d                  %d\n", i, dist[i]);
    }
}

void dijkstra(int **graph, int src)
{
  int dist[V];
  bool sptSet[V];
  for(int i = 0; i < V; i++)
    {
      dist[i] = INT_MAX, sptSet[i] = false;
    }
  dist[src] = 0; // distance from src to src is 0.
  
  for(int count = 0; count < V-1; count++) // why V-1?
    {
      int u = minDistance(dist, sptSet);
      sptSet[u] = true;
      for(int v = 0; v < V; v++)
	{
	  if(sptSet[v] == false && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
	    {
	      dist[v] = dist[u] + graph[u][v];
	      // Backtrace back to node u.
	    }
	}
    }
  printSolution(dist, V);
}

int **createAdjacency()
{
  int numVertices = 72;
  int **Adj = 0;
  Adj = new int *[numVertices];
  
  for (int i = 0; i < numVertices; i++)
  {
    Adj[i] = new int [numVertices];
    for (int j = 0; j < numVertices; j++)
  	{
  	  Adj[i][j] = 0;
  	}
  }
  Adj[0][1] = 1;
  Adj[0][6] = 1;
  Adj[1][0] = 1;
  Adj[1][2] = 1;
  Adj[1][7] = 1;
  Adj[2][1] = 1;
  Adj[2][9] = 1;
  Adj[3][4] = 1;
  Adj[3][10] = 1;
  Adj[4][3] = 1;
  Adj[4][5] = 1;
  Adj[4][12] = 1;
  Adj[5][4] = 1;
  Adj[5][13] = 1;
  Adj[6][0] = 1;
  Adj[6][7] = 1;
  Adj[6][14] = 1;
  Adj[7][6] = 1;
  Adj[7][1] = 1;
  Adj[7][8] = 1;
  Adj[7][15] = 1;
  Adj[8][7] = 1;
  Adj[8][9] = 1;
  Adj[8][16] = 1;
  Adj[9][8] = 1;
  Adj[9][2] = 1;
  Adj[9][10] = 1;
  Adj[10][9] = 1;
  Adj[10][3] = 1;
  Adj[10][11] = 1;
  Adj[11][10] = 1;
  Adj[11][12] = 1;
  Adj[11][19] = 1;
  Adj[12][11] = 1;
  Adj[12][4] = 1;
  Adj[12][13] = 1;
  Adj[12][20] = 1;
  Adj[13][12] = 1;
  Adj[13][5] = 1;
  Adj[13][21] = 1;
  Adj[14][6] = 1;
  Adj[14][15] = 1;
  Adj[14][26] = 1;
  Adj[15][14] = 1;
  Adj[15][7] = 1;
  Adj[15][27] = 1;
  Adj[16][8] = 1;
  Adj[16][17] = 1;
  Adj[17][16] = 1;
  Adj[17][23] = 1;
  Adj[18][19] = 1;
  Adj[18][24] = 1;
  Adj[19][18] = 1;
  Adj[19][11] = 1;
  Adj[20][12] = 1;
  Adj[20][21] = 1;
  Adj[20][30] = 1;
  Adj[21][20] = 1;
  Adj[21][13] = 1;
  Adj[21][31] = 1;
  Adj[22][23] = 1;
  Adj[22][28] = 1;
  Adj[23][22] = 1;
  Adj[23][17] = 1;
  Adj[23][24] = 1;
  Adj[24][23] = 1;
  Adj[24][18] = 1;
  Adj[24][25] = 1;
  Adj[25][24] = 1;
  Adj[25][29] = 1;
  Adj[26][14] = 1;
  Adj[26][27] = 1;
  Adj[26][32] = 1;
  Adj[27][26] = 1;
  Adj[27][15] = 1;
  Adj[27][28] = 1;
  Adj[27][40] = 1;
  Adj[28][27] = 1;
  Adj[28][22] = 1;
  Adj[28][34] = 1;
  Adj[29][25] = 1;
  Adj[29][30] = 1;
  Adj[29][35] = 1;
  Adj[30][29] = 1;
  Adj[30][20] = 1;
  Adj[30][31] = 1;
  Adj[30][45] = 1;
  Adj[31][30] = 1;
  Adj[31][21] = 1;
  Adj[31][37] = 1;
  Adj[32][26] = 1;
  Adj[32][33] = 1;
  Adj[33][32] = 1;
  Adj[33][39] = 1;
  Adj[34][28] = 1;
  Adj[34][35] = 1;
  Adj[34][41] = 1;
  Adj[35][34] = 1;
  Adj[35][29] = 1;
  Adj[35][44] = 1;
  Adj[36][37] = 1;
  Adj[36][46] = 1;
  Adj[37][36] = 1;
  Adj[37][31] = 1;
  Adj[38][39] = 1;
  Adj[38][48] = 1;
  Adj[39][38] = 1;
  Adj[39][33] = 1;
  Adj[39][40] = 1;
  Adj[40][39] = 1;
  Adj[40][27] = 1;
  Adj[40][41] = 1;
  Adj[40][50] = 1;
  Adj[41][40] = 1;
  Adj[41][34] = 1;
  Adj[41][42] = 1;
  Adj[42][41] = 1;
  Adj[42][52] = 1;
  Adj[43][53] = 1;
  Adj[43][44] = 1;
  Adj[44][43] = 1;
  Adj[44][35] = 1;
  Adj[44][45] = 1;
  Adj[45][44] = 1;
  Adj[45][30] = 1;
  Adj[45][46] = 1;
  Adj[45][55] = 1;
  Adj[46][45] = 1;
  Adj[46][36] = 1;
  Adj[46][47] = 1;
  Adj[47][46] = 1;
  Adj[47][57] = 1;
  Adj[48][38] = 1;
  Adj[48][49] = 1;
  Adj[49][48] = 1;
  Adj[49][59] = 1;
  Adj[50][40] = 1;
  Adj[50][51] = 1;
  Adj[50][60] = 1;
  Adj[51][50] = 1;
  Adj[51][52] = 1;
  Adj[51][61] = 1;
  Adj[52][51] = 1;
  Adj[52][42] = 1;
  Adj[52][53] = 1;
  Adj[53][52] = 1;
  Adj[53][43] = 1;
  Adj[53][54] = 1;
  Adj[54][53] = 1;
  Adj[54][55] = 1;
  Adj[54][64] = 1;
  Adj[55][54] = 1;
  Adj[55][45] = 1;
  Adj[55][65] = 1;
  Adj[56][66] = 1;
  Adj[56][57] = 1;
  Adj[57][56] = 1;
  Adj[57][47] = 1;
  Adj[58][59] = 1;
  Adj[58][68] = 1;
  Adj[59][58] = 1;
  Adj[59][49] = 1;
  Adj[59][60] = 1;
  Adj[60][59] = 1;
  Adj[60][50] = 1;
  Adj[61][51] = 1;
  Adj[61][62] = 1;
  Adj[62][61] = 1;
  Adj[62][69] = 1;
  Adj[63][64] = 1;
  Adj[63][70] = 1;
  Adj[64][63] = 1;
  Adj[64][54] = 1;
  Adj[65][55] = 1;
  Adj[65][66] = 1;
  Adj[66][65] = 1;
  Adj[66][56] = 1;
  Adj[66][67] = 1;
  Adj[67][66] = 1;
  Adj[67][71] = 1;
  Adj[68][58] = 1;
  Adj[68][69] = 1;
  Adj[69][68] = 1;
  Adj[69][62] = 1;
  Adj[69][70] = 1;
  Adj[70][69] = 1;
  Adj[70][63] = 1;
  Adj[70][71] = 1;
  Adj[71][70] = 1;
  Adj[71][67] = 1;
  return Adj;
}

std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>> turningPoints(sf::RenderWindow &window)
{
  std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>> points;
  int sizeX = window.getSize().x;
  int sizeY = window.getSize().y;

  sf::CircleShape point1(5);
  sf::CircleShape point2(5);
  sf::CircleShape point3(5);
  sf::CircleShape point4(5);
  sf::CircleShape point5(5);
  sf::CircleShape point6(5);
  sf::CircleShape point7(5);
  sf::CircleShape point8(5);
  sf::CircleShape point9(5);
  sf::CircleShape point10(5);
  sf::CircleShape point11(5);
  sf::CircleShape point12(5);
  sf::CircleShape point13(5);
  sf::CircleShape point14(5);
  sf::CircleShape point15(5);
  sf::CircleShape point16(5);
  sf::CircleShape point17(5);
  sf::CircleShape point18(5);
  sf::CircleShape point19(5);
  sf::CircleShape point20(5);
  sf::CircleShape point21(5);
  sf::CircleShape point22(5);
  sf::CircleShape point23(5);
  sf::CircleShape point24(5);
  sf::CircleShape point25(5);
  sf::CircleShape point26(5);
  sf::CircleShape point27(5);
  sf::CircleShape point28(5);
  sf::CircleShape point29(5);
  sf::CircleShape point30(5);
  sf::CircleShape point31(5);
  sf::CircleShape point32(5);
  sf::CircleShape point33(5);
  sf::CircleShape point34(5);
  sf::CircleShape point35(5);
  sf::CircleShape point36(5);
  sf::CircleShape point37(5);
  sf::CircleShape point38(5);
  sf::CircleShape point39(5);
  sf::CircleShape point40(5);
  sf::CircleShape point41(5);
  sf::CircleShape point42(5);
  sf::CircleShape point43(5);
  sf::CircleShape point44(5);
  sf::CircleShape point45(5);
  sf::CircleShape point46(5);
  sf::CircleShape point47(5);
  sf::CircleShape point48(5);
  sf::CircleShape point49(5);
  sf::CircleShape point50(5);
  sf::CircleShape point51(5);
  sf::CircleShape point52(5);
  sf::CircleShape point53(5);
  sf::CircleShape point54(5);
  sf::CircleShape point55(5);
  sf::CircleShape point56(5);
  sf::CircleShape point57(5);
  sf::CircleShape point58(5);
  sf::CircleShape point59(5);
  sf::CircleShape point60(5);
  sf::CircleShape point61(5);
  sf::CircleShape point62(5);
  sf::CircleShape point63(5);
  sf::CircleShape point64(5);
  sf::CircleShape point65(5);
  sf::CircleShape point66(5);
  sf::CircleShape point67(5);
  sf::CircleShape point68(5);
  sf::CircleShape point69(5);
  sf::CircleShape point70(5);
  sf::CircleShape point71(5);
  sf::CircleShape point72(5);

  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T1;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T2;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T3;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T4;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T5;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T6;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T7;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T8;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T9;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T10;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T11;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T12;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T13;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T14;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T15;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T16;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T17;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T18;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T19;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T20;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T21;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T22;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T23;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T24;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T25;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T26;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T27;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T28;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T29;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T30;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T31;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T32;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T33;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T34;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T35;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T36;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T37;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T38;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T39;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T40;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T41;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T42;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T43;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T44;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T45;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T46;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T47;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T48;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T49;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T50;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T51;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T52;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T53;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T54;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T55;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T56;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T57;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T58;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T59;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T60;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T61;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T62;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T63;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T64;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T65;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T66;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T67;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T68;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T69;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T70;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T71;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> T72;
  
  point1.setFillColor(sf::Color::Red);
  point1.setOrigin(point1.getOrigin().x+point1.getLocalBounds().width/2, point1.getOrigin().y+point1.getLocalBounds().height/2);
  point1.setPosition(sizeX/2*1.05, sizeY/2*1.5);

  point2.setFillColor(sf::Color::Red);
  point2.setOrigin(point2.getOrigin().x+point2.getLocalBounds().width/2, point2.getOrigin().y+point2.getLocalBounds().height/2);
  point2.setPosition(sizeX/2*0.94, sizeY/2*1.5);

  point3.setFillColor(sf::Color::Red);
  point3.setOrigin(point3.getOrigin().x+point3.getLocalBounds().width/2, point3.getOrigin().y+point3.getLocalBounds().height/2);
  point3.setPosition(sizeX/2*1.22, sizeY/2*1.5);

  point4.setFillColor(sf::Color::Red);
  point4.setOrigin(point4.getOrigin().x+point4.getLocalBounds().width/2, point4.getOrigin().y+point4.getLocalBounds().height/2);
  point4.setPosition(sizeX/2*0.77, sizeY/2*1.5);

  point5.setFillColor(sf::Color::Red);
  point5.setOrigin(point5.getOrigin().x+point5.getLocalBounds().width/2, point5.getOrigin().y+point5.getLocalBounds().height/2);
  point5.setPosition(sizeX/2*1.33, sizeY/2*1.5);

  point6.setFillColor(sf::Color::Red);
  point6.setOrigin(point6.getOrigin().x+point6.getLocalBounds().width/2, point6.getOrigin().y+point6.getLocalBounds().height/2);
  point6.setPosition(sizeX/2*0.65, sizeY/2*1.5);

  point7.setFillColor(sf::Color::Red);
  point7.setOrigin(point7.getOrigin().x+point7.getLocalBounds().width/2, point7.getOrigin().y+point7.getLocalBounds().height/2);
  point7.setPosition(sizeX/2*1.05, sizeY/2*1.3);

  point8.setFillColor(sf::Color::Red);
  point8.setOrigin(point8.getOrigin().x+point8.getLocalBounds().width/2, point8.getOrigin().y+point8.getLocalBounds().height/2);
  point8.setPosition(sizeX/2*0.94, sizeY/2*1.3);

  point9.setFillColor(sf::Color::Red);
  point9.setOrigin(point9.getOrigin().x+point9.getLocalBounds().width/2, point9.getOrigin().y+point9.getLocalBounds().height/2);
  point9.setPosition(sizeX/2*1.22, sizeY/2*1.3);

  point10.setFillColor(sf::Color::Red);
  point10.setOrigin(point10.getOrigin().x+point10.getLocalBounds().width/2, point10.getOrigin().y+point10.getLocalBounds().height/2);
  point10.setPosition(sizeX/2*0.77, sizeY/2*1.3);

  point11.setFillColor(sf::Color::Red);
  point11.setOrigin(point11.getOrigin().x+point11.getLocalBounds().width/2, point11.getOrigin().y+point11.getLocalBounds().height/2);
  point11.setPosition(sizeX/2*1.33, sizeY/2*1.3);

  point12.setFillColor(sf::Color::Red);
  point12.setOrigin(point12.getOrigin().x+point12.getLocalBounds().width/2, point12.getOrigin().y+point12.getLocalBounds().height/2);
  point12.setPosition(sizeX/2*0.65, sizeY/2*1.3);

  point13.setFillColor(sf::Color::Red);
  point13.setOrigin(point13.getOrigin().x+point13.getLocalBounds().width/2, point13.getOrigin().y+point13.getLocalBounds().height/2);
  point13.setPosition(sizeX/2*1.05, sizeY/2*1.7);

  point14.setFillColor(sf::Color::Red);
  point14.setOrigin(point14.getOrigin().x+point14.getLocalBounds().width/2, point14.getOrigin().y+point14.getLocalBounds().height/2);
  point14.setPosition(sizeX/2*0.94, sizeY/2*1.7);

  point15.setFillColor(sf::Color::Red);
  point15.setOrigin(point15.getOrigin().x+point15.getLocalBounds().width/2, point15.getOrigin().y+point15.getLocalBounds().height/2);
  point15.setPosition(sizeX/2*1.22, sizeY/2*1.7);

  point16.setFillColor(sf::Color::Red);
  point16.setOrigin(point16.getOrigin().x+point16.getLocalBounds().width/2, point16.getOrigin().y+point16.getLocalBounds().height/2);
  point16.setPosition(sizeX/2*0.77, sizeY/2*1.7);

  point17.setFillColor(sf::Color::Red);
  point17.setOrigin(point17.getOrigin().x+point17.getLocalBounds().width/2, point17.getOrigin().y+point17.getLocalBounds().height/2);
  point17.setPosition(sizeX/2*1.33, sizeY/2*1.7);

  point18.setFillColor(sf::Color::Red);
  point18.setOrigin(point18.getOrigin().x+point18.getLocalBounds().width/2, point18.getOrigin().y+point18.getLocalBounds().height/2);
  point18.setPosition(sizeX/2*0.65, sizeY/2*1.7);

  point19.setFillColor(sf::Color::Red);
  point19.setOrigin(point19.getOrigin().x+point19.getLocalBounds().width/2, point19.getOrigin().y+point19.getLocalBounds().height/2);
  point19.setPosition(sizeX/2*1.22, sizeY/2*1.12);

  point20.setFillColor(sf::Color::Red);
  point20.setOrigin(point20.getOrigin().x+point20.getLocalBounds().width/2, point20.getOrigin().y+point20.getLocalBounds().height/2);
  point20.setPosition(sizeX/2*0.77, sizeY/2*1.12);

  point21.setFillColor(sf::Color::Red);
  point21.setOrigin(point21.getOrigin().x+point21.getLocalBounds().width/2, point21.getOrigin().y+point21.getLocalBounds().height/2);
  point21.setPosition(sizeX/2*1.22, sizeY/2*0.93);

  point22.setFillColor(sf::Color::Red);
  point22.setOrigin(point22.getOrigin().x+point22.getLocalBounds().width/2, point22.getOrigin().y+point22.getLocalBounds().height/2);
  point22.setPosition(sizeX/2*0.77, sizeY/2*0.93);

  point23.setFillColor(sf::Color::Red);
  point23.setOrigin(point23.getOrigin().x+point23.getLocalBounds().width/2, point23.getOrigin().y+point23.getLocalBounds().height/2);
  point23.setPosition(sizeX/2*1.22, sizeY/2*0.77);

  point24.setFillColor(sf::Color::Red);
  point24.setOrigin(point24.getOrigin().x+point24.getLocalBounds().width/2, point24.getOrigin().y+point24.getLocalBounds().height/2);
  point24.setPosition(sizeX/2*0.77, sizeY/2*0.77);

  point25.setFillColor(sf::Color::Red);
  point25.setOrigin(point25.getOrigin().x+point25.getLocalBounds().width/2, point25.getOrigin().y+point25.getLocalBounds().height/2);
  point25.setPosition(sizeX/2*1.05, sizeY/2*0.77);

  point26.setFillColor(sf::Color::Red);
  point26.setOrigin(point26.getOrigin().x+point26.getLocalBounds().width/2, point26.getOrigin().y+point26.getLocalBounds().height/2);
  point26.setPosition(sizeX/2*0.94, sizeY/2*0.77);

  point27.setFillColor(sf::Color::Red);
  point27.setOrigin(point27.getOrigin().x+point27.getLocalBounds().width/2, point27.getOrigin().y+point27.getLocalBounds().height/2);
  point27.setPosition(sizeX/2*1.05, sizeY/2*0.58);

  point28.setFillColor(sf::Color::Red);
  point28.setOrigin(point28.getOrigin().x+point28.getLocalBounds().width/2, point28.getOrigin().y+point28.getLocalBounds().height/2);
  point28.setPosition(sizeX/2*0.94, sizeY/2*0.58);

  point29.setFillColor(sf::Color::Red);
  point29.setOrigin(point29.getOrigin().x+point29.getLocalBounds().width/2, point29.getOrigin().y+point29.getLocalBounds().height/2);
  point29.setPosition(sizeX/2*1.22, sizeY/2*0.58);

  point30.setFillColor(sf::Color::Red);
  point30.setOrigin(point30.getOrigin().x+point30.getLocalBounds().width/2, point30.getOrigin().y+point30.getLocalBounds().height/2);
  point30.setPosition(sizeX/2*0.77, sizeY/2*0.58);

  point31.setFillColor(sf::Color::Red);
  point31.setOrigin(point31.getOrigin().x+point31.getLocalBounds().width/2, point31.getOrigin().y+point31.getLocalBounds().height/2);
  point31.setPosition(sizeX/2*1.05, sizeY/2*1.9);

  point32.setFillColor(sf::Color::Red);
  point32.setOrigin(point32.getOrigin().x+point32.getLocalBounds().width/2, point32.getOrigin().y+point32.getLocalBounds().height/2);
  point32.setPosition(sizeX/2*0.94, sizeY/2*1.9);

  point33.setFillColor(sf::Color::Red);
  point33.setOrigin(point33.getOrigin().x+point33.getLocalBounds().width/2, point33.getOrigin().y+point33.getLocalBounds().height/2);
  point33.setPosition(sizeX/2*0.54, sizeY/2*1.5);

  point34.setFillColor(sf::Color::Red);
  point34.setOrigin(point34.getOrigin().x+point34.getLocalBounds().width/2, point34.getOrigin().y+point34.getLocalBounds().height/2);
  point34.setPosition(sizeX/2*0.54, sizeY/2*1.7);

  point35.setFillColor(sf::Color::Red);
  point35.setOrigin(point35.getOrigin().x+point35.getLocalBounds().width/2, point35.getOrigin().y+point35.getLocalBounds().height/2);
  point35.setPosition(sizeX/2*0.54, sizeY/2*1.3);

  point36.setFillColor(sf::Color::Red);
  point36.setOrigin(point36.getOrigin().x+point36.getLocalBounds().width/2, point36.getOrigin().y+point36.getLocalBounds().height/2);
  point36.setPosition(sizeX/2*0.45, sizeY/2*1.5);

  point37.setFillColor(sf::Color::Red);
  point37.setOrigin(point37.getOrigin().x+point37.getLocalBounds().width/2, point37.getOrigin().y+point37.getLocalBounds().height/2);
  point37.setPosition(sizeX/2*0.45, sizeY/2*1.3);

  point38.setFillColor(sf::Color::Red);
  point38.setOrigin(point38.getOrigin().x+point38.getLocalBounds().width/2, point38.getOrigin().y+point38.getLocalBounds().height/2);
  point38.setPosition(sizeX/2*0.45, sizeY/2*1.7);

  point39.setFillColor(sf::Color::Red);
  point39.setOrigin(point39.getOrigin().x+point39.getLocalBounds().width/2, point39.getOrigin().y+point39.getLocalBounds().height/2);
  point39.setPosition(sizeX/2*0.45, sizeY/2*1.9);

  point40.setFillColor(sf::Color::Red);
  point40.setOrigin(point40.getOrigin().x+point40.getLocalBounds().width/2, point40.getOrigin().y+point40.getLocalBounds().height/2);
  point40.setPosition(sizeX/2*1.55, sizeY/2*1.9);

  point41.setFillColor(sf::Color::Red);
  point41.setOrigin(point41.getOrigin().x+point41.getLocalBounds().width/2, point41.getOrigin().y+point41.getLocalBounds().height/2);
  point41.setPosition(sizeX/2*1.55, sizeY/2*1.7);

  point42.setFillColor(sf::Color::Red);
  point42.setOrigin(point42.getOrigin().x+point42.getLocalBounds().width/2, point42.getOrigin().y+point42.getLocalBounds().height/2);
  point42.setPosition(sizeX/2*1.45, sizeY/2*1.7);

  point43.setFillColor(sf::Color::Red);
  point43.setOrigin(point43.getOrigin().x+point43.getLocalBounds().width/2, point43.getOrigin().y+point43.getLocalBounds().height/2);
  point43.setPosition(sizeX/2*1.55, sizeY/2*1.5);

  point44.setFillColor(sf::Color::Red);
  point44.setOrigin(point44.getOrigin().x+point44.getLocalBounds().width/2, point44.getOrigin().y+point44.getLocalBounds().height/2);
  point44.setPosition(sizeX/2*1.45, sizeY/2*1.5);

  point45.setFillColor(sf::Color::Red);
  point45.setOrigin(point45.getOrigin().x+point45.getLocalBounds().width/2, point45.getOrigin().y+point45.getLocalBounds().height/2);
  point45.setPosition(sizeX/2*1.45, sizeY/2*1.3);

  point46.setFillColor(sf::Color::Red);
  point46.setOrigin(point46.getOrigin().x+point46.getLocalBounds().width/2, point46.getOrigin().y+point46.getLocalBounds().height/2);
  point46.setPosition(sizeX/2*1.55, sizeY/2*1.3);

  point47.setFillColor(sf::Color::Red);
  point47.setOrigin(point47.getOrigin().x+point47.getLocalBounds().width/2, point47.getOrigin().y+point47.getLocalBounds().height/2);
  point47.setPosition(sizeX/2*1.55, sizeY/2*1.12);

  point48.setFillColor(sf::Color::Red);
  point48.setOrigin(point48.getOrigin().x+point48.getLocalBounds().width/2, point48.getOrigin().y+point48.getLocalBounds().height/2);
  point48.setPosition(sizeX/2*1.45, sizeY/2*1.12);

  point49.setFillColor(sf::Color::Red);
  point49.setOrigin(point49.getOrigin().x+point49.getLocalBounds().width/2, point49.getOrigin().y+point49.getLocalBounds().height/2);
  point49.setPosition(sizeX/2*0.45, sizeY/2*1.12);

  point50.setFillColor(sf::Color::Red);
  point50.setOrigin(point50.getOrigin().x+point50.getLocalBounds().width/2, point50.getOrigin().y+point50.getLocalBounds().height/2);
  point50.setPosition(sizeX/2*0.54, sizeY/2*1.12);

  point51.setFillColor(sf::Color::Red);
  point51.setOrigin(point51.getOrigin().x+point51.getLocalBounds().width/2, point51.getOrigin().y+point51.getLocalBounds().height/2);
  point51.setPosition(sizeX/2*0.65, sizeY/2*0.93);

  point52.setFillColor(sf::Color::Red);
  point52.setOrigin(point52.getOrigin().x+point52.getLocalBounds().width/2, point52.getOrigin().y+point52.getLocalBounds().height/2);
  point52.setPosition(sizeX/2*0.45, sizeY/2*0.93);

  point53.setFillColor(sf::Color::Red);
  point53.setOrigin(point53.getOrigin().x+point53.getLocalBounds().width/2, point53.getOrigin().y+point53.getLocalBounds().height/2);
  point53.setPosition(sizeX/2*1.33, sizeY/2*0.93);

  point54.setFillColor(sf::Color::Red);
  point54.setOrigin(point54.getOrigin().x+point54.getLocalBounds().width/2, point54.getOrigin().y+point54.getLocalBounds().height/2);
  point54.setPosition(sizeX/2*1.55, sizeY/2*0.93);

  point55.setFillColor(sf::Color::Red);
  point55.setOrigin(point55.getOrigin().x+point55.getLocalBounds().width/2, point55.getOrigin().y+point55.getLocalBounds().height/2);
  point55.setPosition(sizeX/2*0.65, sizeY/2*0.58);

  point56.setFillColor(sf::Color::Red);
  point56.setOrigin(point56.getOrigin().x+point56.getLocalBounds().width/2, point56.getOrigin().y+point56.getLocalBounds().height/2);
  point56.setPosition(sizeX/2*0.45, sizeY/2*0.58);

  point57.setFillColor(sf::Color::Red);
  point57.setOrigin(point57.getOrigin().x+point57.getLocalBounds().width/2, point57.getOrigin().y+point57.getLocalBounds().height/2);
  point57.setPosition(sizeX/2*1.33, sizeY/2*0.58);

  point58.setFillColor(sf::Color::Red);
  point58.setOrigin(point58.getOrigin().x+point58.getLocalBounds().width/2, point58.getOrigin().y+point58.getLocalBounds().height/2);
  point58.setPosition(sizeX/2*1.55, sizeY/2*0.58);

  point59.setFillColor(sf::Color::Red);
  point59.setOrigin(point59.getOrigin().x+point59.getLocalBounds().width/2, point59.getOrigin().y+point59.getLocalBounds().height/2);
  point59.setPosition(sizeX/2*0.45, sizeY/2*0.40);

  point60.setFillColor(sf::Color::Red);
  point60.setOrigin(point60.getOrigin().x+point60.getLocalBounds().width/2, point60.getOrigin().y+point60.getLocalBounds().height/2);
  point60.setPosition(sizeX/2*0.65, sizeY/2*0.40);

  point61.setFillColor(sf::Color::Red);
  point61.setOrigin(point61.getOrigin().x+point61.getLocalBounds().width/2, point61.getOrigin().y+point61.getLocalBounds().height/2);
  point61.setPosition(sizeX/2*0.77, sizeY/2*0.40);

  point62.setFillColor(sf::Color::Red);
  point62.setOrigin(point62.getOrigin().x+point62.getLocalBounds().width/2, point62.getOrigin().y+point62.getLocalBounds().height/2);
  point62.setPosition(sizeX/2*0.94, sizeY/2*0.40);

  point63.setFillColor(sf::Color::Red);
  point63.setOrigin(point63.getOrigin().x+point63.getLocalBounds().width/2, point63.getOrigin().y+point63.getLocalBounds().height/2);
  point63.setPosition(sizeX/2*1.05, sizeY/2*0.40);

  point64.setFillColor(sf::Color::Red);
  point64.setOrigin(point64.getOrigin().x+point64.getLocalBounds().width/2, point64.getOrigin().y+point64.getLocalBounds().height/2);
  point64.setPosition(sizeX/2*1.22, sizeY/2*0.40);

  point65.setFillColor(sf::Color::Red);
  point65.setOrigin(point65.getOrigin().x+point65.getLocalBounds().width/2, point65.getOrigin().y+point65.getLocalBounds().height/2);
  point65.setPosition(sizeX/2*1.33, sizeY/2*0.40);

  point66.setFillColor(sf::Color::Red);
  point66.setOrigin(point66.getOrigin().x+point66.getLocalBounds().width/2, point66.getOrigin().y+point66.getLocalBounds().height/2);
  point66.setPosition(sizeX/2*1.55, sizeY/2*0.40);

  point67.setFillColor(sf::Color::Red);
  point67.setOrigin(point67.getOrigin().x+point67.getLocalBounds().width/2, point67.getOrigin().y+point67.getLocalBounds().height/2);
  point67.setPosition(sizeX/2*0.65, sizeY/2*0.1);

  point68.setFillColor(sf::Color::Red);
  point68.setOrigin(point68.getOrigin().x+point68.getLocalBounds().width/2, point68.getOrigin().y+point68.getLocalBounds().height/2);
  point68.setPosition(sizeX/2*0.94, sizeY/2*0.1);

  point69.setFillColor(sf::Color::Red);
  point69.setOrigin(point69.getOrigin().x+point69.getLocalBounds().width/2, point69.getOrigin().y+point69.getLocalBounds().height/2);
  point69.setPosition(sizeX/2*1.05, sizeY/2*0.1);

  point70.setFillColor(sf::Color::Red);
  point70.setOrigin(point70.getOrigin().x+point70.getLocalBounds().width/2, point70.getOrigin().y+point70.getLocalBounds().height/2);
  point70.setPosition(sizeX/2*1.33, sizeY/2*0.1);

  point71.setFillColor(sf::Color::Red);
  point71.setOrigin(point71.getOrigin().x+point71.getLocalBounds().width/2, point71.getOrigin().y+point71.getLocalBounds().height/2);
  point71.setPosition(sizeX/2*1.55, sizeY/2*0.1);

  point72.setFillColor(sf::Color::Red);
  point72.setOrigin(point72.getOrigin().x+point72.getLocalBounds().width/2, point72.getOrigin().y+point72.getLocalBounds().height/2);
  point72.setPosition(sizeX/2*0.45, sizeY/2*0.1);
  
  T1=std::make_tuple(point1, "Left", "Right", "Up", "None", 53);
  T2=std::make_tuple(point2, "Left", "Right", "Up", "None", 52);
  T3=std::make_tuple(point3, "Left", "Right", "None", "Down", 54);
  T4=std::make_tuple(point4, "Left", "Right", "None", "Down", 51);
  T5=std::make_tuple(point5, "Left", "None", "Up", "Down", 55);
  T6=std::make_tuple(point6, "None", "Right", "Up", "Down", 50);
  T7=std::make_tuple(point7, "None", "Right", "None", "Down", 43);
  T8=std::make_tuple(point8, "Left", "None", "None", "Down", 42);
  T9=std::make_tuple(point9, "Left", "Right", "Up", "None", 44);
  T10=std::make_tuple(point10, "Left", "Right", "Up", "None", 41);
  T11=std::make_tuple(point11, "Left", "Right", "Up", "Down", 45);
  T12=std::make_tuple(point12, "Left", "Right", "Up", "Down", 40);
  T13=std::make_tuple(point13, "None", "Right", "None", "Down", 63);
  T14=std::make_tuple(point14, "Left", "None", "None", "Down", 62);
  T15=std::make_tuple(point15, "Left", "None", "Up", "None", 64);
  T16=std::make_tuple(point16, "None", "Right", "Up", "None", 61);
  T17=std::make_tuple(point17, "None", "Right", "Up", "None", 65);
  T18=std::make_tuple(point18, "Left", "None", "Up", "None", 60);
  T19=std::make_tuple(point19, "Left", "None", "Up", "Down", 35);
  T20=std::make_tuple(point20, "None", "Right", "Up", "Down", 34);
  T21=std::make_tuple(point21, "None", "Right", "Up", "Down", 29);
  T22=std::make_tuple(point22, "Left", "None", "Up", "Down", 28);
  T23=std::make_tuple(point23, "Left", "None", "None", "Down", 25);
  T24=std::make_tuple(point24, "None", "Right", "None", "Down", 22);
  T25=std::make_tuple(point25, "Left", "Right", "Up", "None", 24);
  T26=std::make_tuple(point26, "Left", "Right", "Up", "None", 23);
  T27=std::make_tuple(point27, "None", "Right", "None", "Down", 18);
  T28=std::make_tuple(point28, "Left", "None", "None", "Down", 17);
  T29=std::make_tuple(point29, "Left", "None", "Up", "None", 19);
  T30=std::make_tuple(point30, "None", "Right", "Up", "None", 16);
  T31=std::make_tuple(point31, "Left", "Right", "Up", "None", 70);
  T32=std::make_tuple(point32, "Left", "Right", "Up", "None", 69);
  T33=std::make_tuple(point33, "Left", "None", "None", "Down", 49);
  T34=std::make_tuple(point34, "Left", "Right", "Up", "None", 59);
  T35=std::make_tuple(point35, "Left", "Right", "Up", "None", 39);
  T36=std::make_tuple(point36, "None", "Right", "Up", "None", 48);
  T37=std::make_tuple(point37, "None", "Right", "None", "Down", 38);
  T38=std::make_tuple(point38, "None", "Right", "None", "Down", 58);
  T39=std::make_tuple(point39, "None", "Right", "Up", "None", 68);
  T40=std::make_tuple(point40, "Left", "None", "Up", "None", 71);
  T41=std::make_tuple(point41, "Left", "None", "None", "Down", 67);
  T42=std::make_tuple(point42, "Left", "Right", "Up", "None", 66);
  T43=std::make_tuple(point43, "Left", "None", "Up", "None", 57);
  T44=std::make_tuple(point44, "None", "Right", "None", "Down", 56);
  T45=std::make_tuple(point45, "Left", "Right", "Up", "None", 46);
  T46=std::make_tuple(point46, "Left", "None", "None", "Down", 47);
  T47=std::make_tuple(point47, "Left", "None", "Up", "None", 37);
  T48=std::make_tuple(point48, "None", "Right", "None", "Down", 36);
  T49=std::make_tuple(point49, "None", "Right", "Up", "None", 32);
  T50=std::make_tuple(point50, "Left", "None", "None", "Down", 33);
  T51=std::make_tuple(point51, "Left", "Right", "Up", "Down", 27);
  T52=std::make_tuple(point52, "None", "Right", "Up", "Down", 26);
  T53=std::make_tuple(point53, "Left", "Right", "Up", "Down", 30);
  T54=std::make_tuple(point54, "Left", "None", "Up", "Down", 31);
  T55=std::make_tuple(point55, "Left", "None", "Up", "Down", 15);
  T56=std::make_tuple(point56, "None", "Right", "Up", "Down", 14);
  T57=std::make_tuple(point57, "None", "Right", "Up", "Down", 20);
  T58=std::make_tuple(point58, "Left", "None", "Up", "Down", 21);
  T59=std::make_tuple(point59, "None", "Right", "Up", "Down", 6);
  T60=std::make_tuple(point60, "Left", "Right", "Up", "Down", 7);
  T61=std::make_tuple(point61, "Left", "Right", "None", "Down", 8);
  T62=std::make_tuple(point62, "Left", "Right", "Up", "None", 9);
  T63=std::make_tuple(point63, "Left", "Right", "Up", "None", 10);
  T64=std::make_tuple(point64, "Left", "Right", "None", "Down", 11);
  T65=std::make_tuple(point65, "Left", "Right", "Up", "Down", 12);
  T66=std::make_tuple(point66, "Left", "None", "Up", "Down", 13);
  T67=std::make_tuple(point67, "Left", "Right", "None", "Down", 1);
  T68=std::make_tuple(point68, "Left", "None", "None", "Down", 2);
  T69=std::make_tuple(point69, "None", "Right", "None", "Down", 3);
  T70=std::make_tuple(point70, "Left", "Right", "None", "Down", 4);
  T71=std::make_tuple(point71, "Left", "None", "None", "Down", 5);
  T72=std::make_tuple(point72, "None", "Right", "None", "Down", 0);
  
  points.push_back(T1);
  points.push_back(T2);
  points.push_back(T3);
  points.push_back(T4);
  points.push_back(T5);
  points.push_back(T6);
  points.push_back(T7);
  points.push_back(T8);
  points.push_back(T9);
  points.push_back(T10);
  points.push_back(T11);
  points.push_back(T12);
  points.push_back(T13);
  points.push_back(T14);
  points.push_back(T15);
  points.push_back(T16);
  points.push_back(T17);
  points.push_back(T18);
  points.push_back(T19);
  points.push_back(T20);
  points.push_back(T21);
  points.push_back(T22);
  points.push_back(T23);
  points.push_back(T24);
  points.push_back(T25);
  points.push_back(T26);
  points.push_back(T27);
  points.push_back(T28);
  points.push_back(T29);
  points.push_back(T30);
  points.push_back(T31);
  points.push_back(T32);
  points.push_back(T33);
  points.push_back(T34);
  points.push_back(T35);
  points.push_back(T36);
  points.push_back(T37);
  points.push_back(T38);
  points.push_back(T39);
  points.push_back(T40);
  points.push_back(T41);
  points.push_back(T42);
  points.push_back(T43);
  points.push_back(T44);
  points.push_back(T45);
  points.push_back(T46);
  points.push_back(T47);
  points.push_back(T48);
  points.push_back(T49);
  points.push_back(T50);
  points.push_back(T51);
  points.push_back(T52);
  points.push_back(T53);
  points.push_back(T54);
  points.push_back(T55);
  points.push_back(T56);
  points.push_back(T57);
  points.push_back(T58);
  points.push_back(T59);
  points.push_back(T60);
  points.push_back(T61);
  points.push_back(T62);
  points.push_back(T63);
  points.push_back(T64);
  points.push_back(T65);
  points.push_back(T66);
  points.push_back(T67);
  points.push_back(T68);
  points.push_back(T69);
  points.push_back(T70);
  points.push_back(T71);
  points.push_back(T72);
  return points;
}

std::vector<sf::ConvexShape> initMap(sf::RenderWindow &window)
{
  std::vector<sf::ConvexShape> mapShapes;
  int sizeX = window.getSize().x;
  int sizeY = window.getSize().y;
  
  sf::ConvexShape conv1;
  sf::ConvexShape conv2;
  sf::ConvexShape conv3;
  sf::ConvexShape conv4;
  sf::ConvexShape conv5;
  sf::ConvexShape conv6;
  sf::ConvexShape conv7;
  sf::ConvexShape conv8;
  sf::ConvexShape conv9;
  sf::ConvexShape conv10;
  sf::ConvexShape conv11;
  sf::ConvexShape conv12;
  sf::ConvexShape conv13;
  sf::ConvexShape conv14;
  sf::ConvexShape conv15;
  sf::ConvexShape conv16;
  sf::ConvexShape conv17;
  sf::ConvexShape conv18;
  sf::ConvexShape conv19;
  sf::ConvexShape conv20;
  sf::ConvexShape conv21;
  sf::ConvexShape conv22;
  sf::ConvexShape conv23;
  sf::ConvexShape conv24;
  sf::ConvexShape conv25;
  sf::ConvexShape conv26;
  sf::ConvexShape conv27;
  sf::ConvexShape conv28;
  sf::ConvexShape conv29;
  sf::ConvexShape conv30;
  
  conv1.setPointCount(8);
  conv1.setPoint(0, sf::Vector2f(0, 0));
  conv1.setPoint(1, sf::Vector2f(0+20, 0));
  conv1.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv1.setPoint(3, sf::Vector2f(0+180, 0-100));
  conv1.setPoint(4, sf::Vector2f(0+180, 0-120));
  conv1.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv1.setPoint(6, sf::Vector2f(0-170, 0-100));
  conv1.setPoint(7, sf::Vector2f(0, 0-100));
  conv1.setOutlineColor(sf::Color::Blue);
  conv1.setFillColor(sf::Color::Transparent);
  conv1.setOutlineThickness(4);
  conv1.setPosition(sizeX*0.495, sizeY*0.90);

  conv2.setPointCount(8);
  conv2.setPoint(0, sf::Vector2f(0, 0));
  conv2.setPoint(1, sf::Vector2f(0+20, 0));
  conv2.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv2.setPoint(3, sf::Vector2f(0+180, 0-100));
  conv2.setPoint(4, sf::Vector2f(0+180, 0-120));
  conv2.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv2.setPoint(6, sf::Vector2f(0-170, 0-100));
  conv2.setPoint(7, sf::Vector2f(0, 0-100));
  conv2.setOutlineColor(sf::Color::Blue);
  conv2.setFillColor(sf::Color::Transparent);
  conv2.setOutlineThickness(4);
  conv2.setPosition(sizeX*0.495, sizeY*0.71);

  conv3.setPointCount(4);
  conv3.setPoint(0, sf::Vector2f(0, 0));
  conv3.setPoint(1, sf::Vector2f(0+180, 0));
  conv3.setPoint(2, sf::Vector2f(0+180, 0-20));
  conv3.setPoint(3, sf::Vector2f(0, 0-20));
  conv3.setOutlineColor(sf::Color::Blue);
  conv3.setFillColor(sf::Color::Transparent);
  conv3.setOutlineThickness(4);
  conv3.setPosition(sizeX*0.55, sizeY*0.71);

  conv4.setPointCount(4);
  conv4.setPoint(0, sf::Vector2f(0, 0));
  conv4.setPoint(1, sf::Vector2f(0+180, 0));
  conv4.setPoint(2, sf::Vector2f(0+180, 0-20));
  conv4.setPoint(3, sf::Vector2f(0, 0-20));
  conv4.setOutlineColor(sf::Color::Blue);
  conv4.setFillColor(sf::Color::Transparent);
  conv4.setOutlineThickness(4);
  conv4.setPosition(sizeX*0.35, sizeY*0.71);

  conv5.setPointCount(6);
  conv5.setPoint(0, sf::Vector2f(0, 0));
  conv5.setPoint(1, sf::Vector2f(0+20, 0));
  conv5.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv5.setPoint(3, sf::Vector2f(0+100, 0-100));
  conv5.setPoint(4, sf::Vector2f(0+100, 0-120));
  conv5.setPoint(5, sf::Vector2f(0, 0-120));
  conv5.setOutlineColor(sf::Color::Blue);
  conv5.setFillColor(sf::Color::Transparent);
  conv5.setOutlineThickness(4);
  conv5.setPosition(sizeX*0.69, sizeY*0.805);

  conv6.setPointCount(6);
  conv6.setPoint(0, sf::Vector2f(0, 0));
  conv6.setPoint(1, sf::Vector2f(0-20, 0));
  conv6.setPoint(2, sf::Vector2f(0-20, 0-100));
  conv6.setPoint(3, sf::Vector2f(0-100, 0-100));
  conv6.setPoint(4, sf::Vector2f(0-100, 0-120));
  conv6.setPoint(5, sf::Vector2f(0, 0-120));
  conv6.setOutlineColor(sf::Color::Blue);
  conv6.setFillColor(sf::Color::Transparent);
  conv6.setOutlineThickness(4);
  conv6.setPosition(sizeX*0.30, sizeY*0.805);

  conv7.setPointCount(8);
  conv7.setPoint(0, sf::Vector2f(0, 0));
  conv7.setPoint(1, sf::Vector2f(0-390, 0));
  conv7.setPoint(2, sf::Vector2f(0-390, 0-20));
  conv7.setPoint(3, sf::Vector2f(0-190, 0-20));
  conv7.setPoint(4, sf::Vector2f(0-190, 0-120));
  conv7.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv7.setPoint(6, sf::Vector2f(0-170, 0-20));
  conv7.setPoint(7, sf::Vector2f(0, 0-20));
  conv7.setOutlineColor(sf::Color::Blue);
  conv7.setFillColor(sf::Color::Transparent);
  conv7.setOutlineThickness(4);
  conv7.setPosition(sizeX*0.45, sizeY*0.9);

  conv8.setPointCount(8);
  conv8.setPoint(0, sf::Vector2f(0, 0));
  conv8.setPoint(1, sf::Vector2f(0+375, 0));
  conv8.setPoint(2, sf::Vector2f(0+375, 0-20));
  conv8.setPoint(3, sf::Vector2f(0+190, 0-20));
  conv8.setPoint(4, sf::Vector2f(0+190, 0-120));
  conv8.setPoint(5, sf::Vector2f(0+170, 0-120));
  conv8.setPoint(6, sf::Vector2f(0+170, 0-20));
  conv8.setPoint(7, sf::Vector2f(0, 0-20));
  conv8.setOutlineColor(sf::Color::Blue);
  conv8.setFillColor(sf::Color::Transparent);
  conv8.setOutlineThickness(4);
  conv8.setPosition(sizeX*0.55, sizeY*0.9);

  conv9.setPointCount(4);
  conv9.setPoint(0, sf::Vector2f(0, 0));
  conv9.setPoint(1, sf::Vector2f(0+350, 0));
  conv9.setPoint(2, sf::Vector2f(0+350, 0-100));
  conv9.setPoint(3, sf::Vector2f(0, 0-100));
  conv9.setOutlineColor(sf::Color::Blue);
  conv9.setFillColor(sf::Color::Transparent);
  conv9.setOutlineThickness(4);
  conv9.setPosition(sizeX*0.405, sizeY*0.52);

  conv10.setPointCount(4);
  conv10.setPoint(0, sf::Vector2f(0, 0));
  conv10.setPoint(1, sf::Vector2f(0+20, 0));
  conv10.setPoint(2, sf::Vector2f(0+20, 0-120));
  conv10.setPoint(3, sf::Vector2f(0, 0-120));
  conv10.setOutlineColor(sf::Color::Blue);
  conv10.setFillColor(sf::Color::Transparent);
  conv10.setOutlineThickness(4);
  conv10.setPosition(sizeX*0.35, sizeY*0.62);

  conv11.setPointCount(4);
  conv11.setPoint(0, sf::Vector2f(0, 0));
  conv11.setPoint(1, sf::Vector2f(0+20, 0));
  conv11.setPoint(2, sf::Vector2f(0+20, 0-120));
  conv11.setPoint(3, sf::Vector2f(0, 0-120));
  conv11.setOutlineColor(sf::Color::Blue);
  conv11.setFillColor(sf::Color::Transparent);
  conv11.setOutlineThickness(4);
  conv11.setPosition(sizeX*0.63, sizeY*0.62);

  conv12.setPointCount(8);
  conv12.setPoint(0, sf::Vector2f(0, 0));
  conv12.setPoint(1, sf::Vector2f(0+20, 0));
  conv12.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv12.setPoint(3, sf::Vector2f(0+180, 0-100));
  conv12.setPoint(4, sf::Vector2f(0+180, 0-120));
  conv12.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv12.setPoint(6, sf::Vector2f(0-170, 0-100));
  conv12.setPoint(7, sf::Vector2f(0, 0-100));
  conv12.setOutlineColor(sf::Color::Blue);
  conv12.setFillColor(sf::Color::Transparent);
  conv12.setOutlineThickness(4);
  conv12.setPosition(sizeX*0.495, sizeY*0.35);

  conv13.setPointCount(8);
  conv13.setPoint(0, sf::Vector2f(0, 0));
  conv13.setPoint(1, sf::Vector2f(0, 0+20));
  conv13.setPoint(2, sf::Vector2f(0+150, 0+20));
  conv13.setPoint(3, sf::Vector2f(0+150, 0+110));
  conv13.setPoint(4, sf::Vector2f(0+170, 0+110));
  conv13.setPoint(5, sf::Vector2f(0+170, 0-100));
  conv13.setPoint(6, sf::Vector2f(0+150, 0-100));
  conv13.setPoint(7, sf::Vector2f(0+150, 0));
  conv13.setOutlineColor(sf::Color::Blue);
  conv13.setFillColor(sf::Color::Transparent);
  conv13.setOutlineThickness(4);
  conv13.setPosition(sizeX*0.55, sizeY*0.33);

  conv14.setPointCount(8);
  conv14.setPoint(0, sf::Vector2f(0, 0));
  conv14.setPoint(1, sf::Vector2f(0, 0+20));
  conv14.setPoint(2, sf::Vector2f(0-160, 0+20));
  conv14.setPoint(3, sf::Vector2f(0-160, 0+110));
  conv14.setPoint(4, sf::Vector2f(0-180, 0+110));
  conv14.setPoint(5, sf::Vector2f(0-180, 0-100));
  conv14.setPoint(6, sf::Vector2f(0-160, 0-100));
  conv14.setPoint(7, sf::Vector2f(0-160, 0));
  conv14.setOutlineColor(sf::Color::Blue);
  conv14.setFillColor(sf::Color::Transparent);
  conv14.setOutlineThickness(4);
  conv14.setPosition(sizeX*0.446, sizeY*0.33);

  conv15.setPointCount(4);
  conv15.setPoint(0, sf::Vector2f(0, 0));
  conv15.setPoint(1, sf::Vector2f(0+100, 0));
  conv15.setPoint(2, sf::Vector2f(0+100, 0-20));
  conv15.setPoint(3, sf::Vector2f(0, 0-20));
  conv15.setOutlineColor(sf::Color::Blue);
  conv15.setFillColor(sf::Color::Transparent);
  conv15.setOutlineThickness(4);
  conv15.setPosition(sizeX*0.247, sizeY*0.26);

  conv16.setPointCount(4);
  conv16.setPoint(0, sf::Vector2f(0, 0));
  conv16.setPoint(1, sf::Vector2f(0+100, 0));
  conv16.setPoint(2, sf::Vector2f(0+100, 0-20));
  conv16.setPoint(3, sf::Vector2f(0, 0-20));
  conv16.setOutlineColor(sf::Color::Blue);
  conv16.setFillColor(sf::Color::Transparent);
  conv16.setOutlineThickness(4);
  conv16.setPosition(sizeX*0.69, sizeY*0.26);

  conv17.setPointCount(4);
  conv17.setPoint(0, sf::Vector2f(0, 0));
  conv17.setPoint(1, sf::Vector2f(0+100, 0));
  conv17.setPoint(2, sf::Vector2f(0+100, 0+70));
  conv17.setPoint(3, sf::Vector2f(0, 0+70));
  conv17.setOutlineColor(sf::Color::Blue);
  conv17.setFillColor(sf::Color::Transparent);
  conv17.setOutlineThickness(4);
  conv17.setPosition(sizeX*0.247, sizeY*0.09);

  conv18.setPointCount(4);
  conv18.setPoint(0, sf::Vector2f(0, 0));
  conv18.setPoint(1, sf::Vector2f(0+100, 0));
  conv18.setPoint(2, sf::Vector2f(0+100, 0+70));
  conv18.setPoint(3, sf::Vector2f(0, 0+70));
  conv18.setOutlineColor(sf::Color::Blue);
  conv18.setFillColor(sf::Color::Transparent);
  conv18.setOutlineThickness(4);
  conv18.setPosition(sizeX*0.69, sizeY*0.09);

  conv19.setPointCount(4);
  conv19.setPoint(0, sf::Vector2f(0, 0));
  conv19.setPoint(1, sf::Vector2f(0+180, 0));
  conv19.setPoint(2, sf::Vector2f(0+180, 0+70));
  conv19.setPoint(3, sf::Vector2f(0, 0+70));
  conv19.setOutlineColor(sf::Color::Blue);
  conv19.setFillColor(sf::Color::Transparent);
  conv19.setOutlineThickness(4);
  conv19.setPosition(sizeX*0.55, sizeY*0.09);

  conv20.setPointCount(4);
  conv20.setPoint(0, sf::Vector2f(0, 0));
  conv20.setPoint(1, sf::Vector2f(0+180, 0));
  conv20.setPoint(2, sf::Vector2f(0+180, 0+70));
  conv20.setPoint(3, sf::Vector2f(0, 0+70));
  conv20.setOutlineColor(sf::Color::Blue);
  conv20.setFillColor(sf::Color::Transparent);
  conv20.setOutlineThickness(4);
  conv20.setPosition(sizeX*0.35, sizeY*0.09);

  conv21.setPointCount(4);
  conv21.setPoint(0, sf::Vector2f(0, 0));
  conv21.setPoint(1, sf::Vector2f(0+1150, 0));
  conv21.setPoint(2, sf::Vector2f(0+1150, 0+1050));
  conv21.setPoint(3, sf::Vector2f(0, 0+1050));
  conv21.setOutlineColor(sf::Color::Blue);
  conv21.setFillColor(sf::Color::Transparent);
  conv21.setOutlineThickness(4);
  conv21.setPosition(sizeX*0.2, sizeY*0.01);

  conv22.setPointCount(6);
  conv22.setPoint(0, sf::Vector2f(0, 0));
  conv22.setPoint(1, sf::Vector2f(0-20, 0));
  conv22.setPoint(2, sf::Vector2f(0-20, 0-100));
  conv22.setPoint(3, sf::Vector2f(0-100, 0-100));
  conv22.setPoint(4, sf::Vector2f(0-100, 0-120));
  conv22.setPoint(5, sf::Vector2f(0, 0-120));
  conv22.setOutlineColor(sf::Color::Blue);
  conv22.setFillColor(sf::Color::Transparent);
  conv22.setOutlineThickness(4);
  conv22.setPosition(sizeX*0.30, sizeY*0.62);

  conv23.setPointCount(6);
  conv23.setPoint(0, sf::Vector2f(0, 0));
  conv23.setPoint(1, sf::Vector2f(0+20, 0));
  conv23.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv23.setPoint(3, sf::Vector2f(0+100, 0-100));
  conv23.setPoint(4, sf::Vector2f(0+100, 0-120));
  conv23.setPoint(5, sf::Vector2f(0, 0-120));
  conv23.setOutlineColor(sf::Color::Blue);
  conv23.setFillColor(sf::Color::Transparent);
  conv23.setOutlineThickness(4);
  conv23.setPosition(sizeX*0.69, sizeY*0.62);

  conv24.setPointCount(4);
  conv24.setPoint(0, sf::Vector2f(0, 0));
  conv24.setPoint(1, sf::Vector2f(0+100, 0));
  conv24.setPoint(2, sf::Vector2f(0+100, 0+110));
  conv24.setPoint(3, sf::Vector2f(0, 0+110));
  conv24.setOutlineColor(sf::Color::Blue);
  conv24.setFillColor(sf::Color::Transparent);
  conv24.setOutlineThickness(4);
  conv24.setPosition(sizeX*0.69, sizeY*0.328);

  conv25.setPointCount(4);
  conv25.setPoint(0, sf::Vector2f(0, 0));
  conv25.setPoint(1, sf::Vector2f(0+100, 0));
  conv25.setPoint(2, sf::Vector2f(0+100, 0+110));
  conv25.setPoint(3, sf::Vector2f(0, 0+110));
  conv25.setOutlineColor(sf::Color::Blue);
  conv25.setFillColor(sf::Color::Transparent);
  conv25.setOutlineThickness(4);
  conv25.setPosition(sizeX*0.245, sizeY*0.328);

  conv26.setPointCount(4);
  conv26.setPoint(0, sf::Vector2f(0, 0));
  conv26.setPoint(1, sf::Vector2f(0+20, 0));
  conv26.setPoint(2, sf::Vector2f(0+20, 0+160));
  conv26.setPoint(3, sf::Vector2f(0, 0+160));
  conv26.setOutlineColor(sf::Color::Blue);
  conv26.setFillColor(sf::Color::Transparent);
  conv26.setOutlineThickness(4);
  conv26.setPosition(sizeX*0.493, sizeY*0.01);

  conv27.setPointCount(4);
  conv27.setPoint(0, sf::Vector2f(0, 0));
  conv27.setPoint(1, sf::Vector2f(0+100, 0));
  conv27.setPoint(2, sf::Vector2f(0+100, 0+20));
  conv27.setPoint(3, sf::Vector2f(0, 0+20));
  conv27.setOutlineColor(sf::Color::Blue);
  conv27.setFillColor(sf::Color::Transparent);
  conv27.setOutlineThickness(4);
  conv27.setPosition(sizeX*0.2, sizeY*0.6);

  conv28.setPointCount(4);
  conv28.setPoint(0, sf::Vector2f(0, 0));
  conv28.setPoint(1, sf::Vector2f(0+100, 0));
  conv28.setPoint(2, sf::Vector2f(0+100, 0+20));
  conv28.setPoint(3, sf::Vector2f(0, 0+20));
  conv28.setOutlineColor(sf::Color::Blue);
  conv28.setFillColor(sf::Color::Transparent);
  conv28.setOutlineThickness(4);
  conv28.setPosition(sizeX*0.2, sizeY*0.785);

  conv29.setPointCount(4);
  conv29.setPoint(0, sf::Vector2f(0, 0));
  conv29.setPoint(1, sf::Vector2f(0+100, 0));
  conv29.setPoint(2, sf::Vector2f(0+100, 0+20));
  conv29.setPoint(3, sf::Vector2f(0, 0+20));
  conv29.setOutlineColor(sf::Color::Blue);
  conv29.setFillColor(sf::Color::Transparent);
  conv29.setOutlineThickness(4);
  conv29.setPosition(sizeX*0.747, sizeY*0.6);

  conv30.setPointCount(4);
  conv30.setPoint(0, sf::Vector2f(0, 0));
  conv30.setPoint(1, sf::Vector2f(0+100, 0));
  conv30.setPoint(2, sf::Vector2f(0+100, 0+20));
  conv30.setPoint(3, sf::Vector2f(0, 0+20));
  conv30.setOutlineColor(sf::Color::Blue);
  conv30.setFillColor(sf::Color::Transparent);
  conv30.setOutlineThickness(4);
  conv30.setPosition(sizeX*0.747, sizeY*0.78);
  
  mapShapes.push_back(conv1);
  mapShapes.push_back(conv2);
  mapShapes.push_back(conv3);
  mapShapes.push_back(conv4);
  mapShapes.push_back(conv5);
  mapShapes.push_back(conv6);
  mapShapes.push_back(conv7);
  mapShapes.push_back(conv8);
  mapShapes.push_back(conv9);
  mapShapes.push_back(conv10);
  mapShapes.push_back(conv11);
  mapShapes.push_back(conv12);
  mapShapes.push_back(conv13);
  mapShapes.push_back(conv14);
  mapShapes.push_back(conv15);
  mapShapes.push_back(conv16);
  mapShapes.push_back(conv17);
  mapShapes.push_back(conv18);
  mapShapes.push_back(conv19);
  mapShapes.push_back(conv20);
  mapShapes.push_back(conv21);
  mapShapes.push_back(conv22);
  mapShapes.push_back(conv23);
  mapShapes.push_back(conv24);
  mapShapes.push_back(conv25);
  mapShapes.push_back(conv26);
  mapShapes.push_back(conv27);
  mapShapes.push_back(conv28);
  mapShapes.push_back(conv29);
  mapShapes.push_back(conv30);
  return mapShapes;
}

int gameOver(sf::RenderWindow &window, sf::Font font)
{
  sf::Text MenuButton("Menu", font, 100);
  sf::Text ExitButton("Exit", font, 100);
  sf::Text TitleText("Game over!", font, 200);
  sf::Event event;
  MenuButton.setFillColor(sf::Color::Black);
  ExitButton.setFillColor(sf::Color::Black);
  TitleText.setFillColor(sf::Color::Red);
  MenuButton.setPosition(window.getSize().x/2-MenuButton.getLocalBounds().width/2, window.getSize().y-MenuButton.getLocalBounds().height*5);
  ExitButton.setPosition(window.getSize().x/2-ExitButton.getLocalBounds().width/2, window.getSize().y-ExitButton.getLocalBounds().height*2);
  TitleText.setPosition(window.getSize().x/2-TitleText.getLocalBounds().width/2, window.getSize().y-TitleText.getLocalBounds().height*7);

  window.setFramerateLimit(60);

  while(window.isOpen())
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
      if (MenuButton.getGlobalBounds().contains(mousePosF))
	{
	  MenuButton.setFillColor(sf::Color::Blue);
	}
      else if (ExitButton.getGlobalBounds().contains(mousePosF))
	{
	  ExitButton.setFillColor(sf::Color::Blue);
	}
      else
	{
	  MenuButton.setFillColor(sf::Color::Black);
	  ExitButton.setFillColor(sf::Color::Black);
	}

      while (window.pollEvent(event))
	{
	  switch(event.type)
	    {
	    case sf::Event::MouseButtonPressed:
	      if (MenuButton.getGlobalBounds().contains(mousePosF))
		{
		  return 0;
		  break;
		}
	      else if (ExitButton.getGlobalBounds().contains(mousePosF))
		{
		  return 1;
		  break;
		}
	    }
	}
      window.clear(sf::Color::White);
      window.draw(MenuButton);
      window.draw(ExitButton);
      window.draw(TitleText);
      window.display();
    }
}
