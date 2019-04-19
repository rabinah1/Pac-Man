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

std::vector<sf::CircleShape> collPoints(sf::RenderWindow &window)
{
  std::vector<sf::CircleShape> collects;
  int sizeX = window.getSize().x;
  int sizeY = window.getSize().y;

  sf::CircleShape collect1(5);
  sf::CircleShape collect2(5);
  sf::CircleShape collect3(5);
  sf::CircleShape collect4(5);
  sf::CircleShape collect5(5);
  sf::CircleShape collect6(5);
  sf::CircleShape collect7(5);
  sf::CircleShape collect8(5);
  sf::CircleShape collect9(5);
  sf::CircleShape collect10(5);
  sf::CircleShape collect11(5);
  sf::CircleShape collect12(5);
  sf::CircleShape collect13(5);
  sf::CircleShape collect14(5);
  sf::CircleShape collect15(5);
  sf::CircleShape collect16(5);
  sf::CircleShape collect17(5);
  sf::CircleShape collect18(5);
  sf::CircleShape collect19(5);
  sf::CircleShape collect20(5);
  sf::CircleShape collect21(5);
  sf::CircleShape collect22(5);
  sf::CircleShape collect23(5);
  sf::CircleShape collect24(5);
  sf::CircleShape collect25(5);
  sf::CircleShape collect26(5);
  sf::CircleShape collect27(5);
  sf::CircleShape collect28(5);
  sf::CircleShape collect29(5);
  sf::CircleShape collect30(5);
  sf::CircleShape collect31(5);
  sf::CircleShape collect32(5);
  sf::CircleShape collect33(5);
  sf::CircleShape collect34(5);
  sf::CircleShape collect35(5);
  sf::CircleShape collect36(5);
  sf::CircleShape collect37(5);
  sf::CircleShape collect38(5);
  sf::CircleShape collect39(5);
  sf::CircleShape collect40(5);
  sf::CircleShape collect41(5);
  sf::CircleShape collect42(5);
  sf::CircleShape collect43(5);
  sf::CircleShape collect44(5);
  sf::CircleShape collect45(5);
  sf::CircleShape collect46(5);
  sf::CircleShape collect47(5);
  sf::CircleShape collect48(5);
  sf::CircleShape collect49(5);
  sf::CircleShape collect50(5);
  sf::CircleShape collect51(5);
  sf::CircleShape collect52(5);
  sf::CircleShape collect53(5);
  sf::CircleShape collect54(5);
  sf::CircleShape collect55(5);
  sf::CircleShape collect56(5);
  sf::CircleShape collect57(5);
  sf::CircleShape collect58(5);
  sf::CircleShape collect59(5);
  sf::CircleShape collect60(5);
  sf::CircleShape collect61(5);
  sf::CircleShape collect62(5);
  sf::CircleShape collect63(5);
  sf::CircleShape collect64(5);
  sf::CircleShape collect65(5);
  sf::CircleShape collect66(5);
  sf::CircleShape collect67(5);
  sf::CircleShape collect68(5);
  sf::CircleShape collect69(5);
  sf::CircleShape collect70(5);
  sf::CircleShape collect71(5);
  sf::CircleShape collect72(5);
  sf::CircleShape collect73(5);
  sf::CircleShape collect74(5);
  sf::CircleShape collect75(5);
  sf::CircleShape collect76(5);
  sf::CircleShape collect77(5);
  sf::CircleShape collect78(5);
  sf::CircleShape collect79(5);
  sf::CircleShape collect80(5);
  sf::CircleShape collect81(5);
  sf::CircleShape collect82(5);
  sf::CircleShape collect83(5);
  sf::CircleShape collect84(5);
  sf::CircleShape collect85(5);
  sf::CircleShape collect86(5);
  sf::CircleShape collect87(5);
  sf::CircleShape collect88(5);
  sf::CircleShape collect89(5);
  sf::CircleShape collect90(5);
  sf::CircleShape collect91(5);
  sf::CircleShape collect92(5);
  sf::CircleShape collect93(5);
  sf::CircleShape collect94(5);
  sf::CircleShape collect95(5);
  sf::CircleShape collect96(5);
  sf::CircleShape collect97(5);
  sf::CircleShape collect98(5);
  sf::CircleShape collect99(5);
  sf::CircleShape collect100(5);
  sf::CircleShape collect101(5);
  sf::CircleShape collect102(5);
  sf::CircleShape collect103(5);
  sf::CircleShape collect104(5);

  collect1.setFillColor(sf::Color::White);
  collect1.setOrigin(collect1.getOrigin().x+collect1.getLocalBounds().width/2, collect1.getOrigin().y+collect1.getLocalBounds().height/2);
  collect1.setPosition(sizeX/2*0.69, sizeY/2*0.1);

  collect2.setFillColor(sf::Color::White);
  collect2.setOrigin(collect2.getOrigin().x+collect2.getLocalBounds().width/2, collect2.getOrigin().y+collect2.getLocalBounds().height/2);
  collect2.setPosition(sizeX/2*0.45, sizeY/2*0.1);

  collect3.setFillColor(sf::Color::White);
  collect3.setOrigin(collect3.getOrigin().x+collect3.getLocalBounds().width/2, collect3.getOrigin().y+collect3.getLocalBounds().height/2);
  collect3.setPosition(sizeX/2*0.57, sizeY/2*0.1);

  collect4.setFillColor(sf::Color::White);
  collect4.setOrigin(collect4.getOrigin().x+collect4.getLocalBounds().width/2, collect4.getOrigin().y+collect4.getLocalBounds().height/2);
  collect4.setPosition(sizeX/2*0.81, sizeY/2*0.1);

  collect5.setFillColor(sf::Color::White);
  collect5.setOrigin(collect5.getOrigin().x+collect5.getLocalBounds().width/2, collect5.getOrigin().y+collect5.getLocalBounds().height/2);
  collect5.setPosition(sizeX/2*0.93, sizeY/2*0.1);

  collect6.setFillColor(sf::Color::White);
  collect6.setOrigin(collect6.getOrigin().x+collect6.getLocalBounds().width/2, collect6.getOrigin().y+collect6.getLocalBounds().height/2);
  collect6.setPosition(sizeX/2*1.05, sizeY/2*0.1);

  collect7.setFillColor(sf::Color::White);
  collect7.setOrigin(collect7.getOrigin().x+collect7.getLocalBounds().width/2, collect7.getOrigin().y+collect7.getLocalBounds().height/2);
  collect7.setPosition(sizeX/2*1.17, sizeY/2*0.1);

  collect8.setFillColor(sf::Color::White);
  collect8.setOrigin(collect8.getOrigin().x+collect8.getLocalBounds().width/2, collect8.getOrigin().y+collect8.getLocalBounds().height/2);
  collect8.setPosition(sizeX/2*1.29, sizeY/2*0.1);

  collect9.setFillColor(sf::Color::White);
  collect9.setOrigin(collect9.getOrigin().x+collect9.getLocalBounds().width/2, collect9.getOrigin().y+collect9.getLocalBounds().height/2);
  collect9.setPosition(sizeX/2*1.41, sizeY/2*0.1);

  collect10.setFillColor(sf::Color::White);
  collect10.setOrigin(collect10.getOrigin().x+collect10.getLocalBounds().width/2, collect10.getOrigin().y+collect10.getLocalBounds().height/2);
  collect10.setPosition(sizeX/2*1.55, sizeY/2*0.1);

  collect11.setFillColor(sf::Color::White);
  collect11.setOrigin(collect11.getOrigin().x+collect11.getLocalBounds().width/2, collect11.getOrigin().y+collect11.getLocalBounds().height/2);
  collect11.setPosition(sizeX/2*0.69, sizeY/2*0.4);

  collect12.setFillColor(sf::Color::White);
  collect12.setOrigin(collect12.getOrigin().x+collect12.getLocalBounds().width/2, collect12.getOrigin().y+collect12.getLocalBounds().height/2);
  collect12.setPosition(sizeX/2*0.45, sizeY/2*0.4);

  collect13.setFillColor(sf::Color::White);
  collect13.setOrigin(collect13.getOrigin().x+collect13.getLocalBounds().width/2, collect13.getOrigin().y+collect13.getLocalBounds().height/2);
  collect13.setPosition(sizeX/2*0.57, sizeY/2*0.4);

  collect14.setFillColor(sf::Color::White);
  collect14.setOrigin(collect14.getOrigin().x+collect14.getLocalBounds().width/2, collect14.getOrigin().y+collect14.getLocalBounds().height/2);
  collect14.setPosition(sizeX/2*0.81, sizeY/2*0.4);

  collect15.setFillColor(sf::Color::White);
  collect15.setOrigin(collect15.getOrigin().x+collect15.getLocalBounds().width/2, collect15.getOrigin().y+collect15.getLocalBounds().height/2);
  collect15.setPosition(sizeX/2*0.93, sizeY/2*0.4);

  collect16.setFillColor(sf::Color::White);
  collect16.setOrigin(collect16.getOrigin().x+collect16.getLocalBounds().width/2, collect16.getOrigin().y+collect16.getLocalBounds().height/2);
  collect16.setPosition(sizeX/2*1.05, sizeY/2*0.4);

  collect17.setFillColor(sf::Color::White);
  collect17.setOrigin(collect17.getOrigin().x+collect17.getLocalBounds().width/2, collect17.getOrigin().y+collect17.getLocalBounds().height/2);
  collect17.setPosition(sizeX/2*1.17, sizeY/2*0.4);

  collect18.setFillColor(sf::Color::White);
  collect18.setOrigin(collect18.getOrigin().x+collect18.getLocalBounds().width/2, collect18.getOrigin().y+collect18.getLocalBounds().height/2);
  collect18.setPosition(sizeX/2*1.29, sizeY/2*0.4);

  collect19.setFillColor(sf::Color::White);
  collect19.setOrigin(collect19.getOrigin().x+collect19.getLocalBounds().width/2, collect19.getOrigin().y+collect19.getLocalBounds().height/2);
  collect19.setPosition(sizeX/2*1.41, sizeY/2*0.4);

  collect20.setFillColor(sf::Color::White);
  collect20.setOrigin(collect20.getOrigin().x+collect20.getLocalBounds().width/2, collect20.getOrigin().y+collect20.getLocalBounds().height/2);
  collect20.setPosition(sizeX/2*1.55, sizeY/2*0.4);

  collect21.setFillColor(sf::Color::White);
  collect21.setOrigin(collect21.getOrigin().x+collect21.getLocalBounds().width/2, collect21.getOrigin().y+collect21.getLocalBounds().height/2);
  collect21.setPosition(sizeX/2*0.45, sizeY/2*0.25);

  collect22.setFillColor(sf::Color::White);
  collect22.setOrigin(collect22.getOrigin().x+collect22.getLocalBounds().width/2, collect22.getOrigin().y+collect22.getLocalBounds().height/2);
  collect22.setPosition(sizeX/2*0.93, sizeY/2*0.25);

  collect23.setFillColor(sf::Color::White);
  collect23.setOrigin(collect23.getOrigin().x+collect23.getLocalBounds().width/2, collect23.getOrigin().y+collect23.getLocalBounds().height/2);
  collect23.setPosition(sizeX/2*1.05, sizeY/2*0.25);

  collect24.setFillColor(sf::Color::White);
  collect24.setOrigin(collect24.getOrigin().x+collect24.getLocalBounds().width/2, collect24.getOrigin().y+collect24.getLocalBounds().height/2);
  collect24.setPosition(sizeX/2*1.55, sizeY/2*0.25);

  collect25.setFillColor(sf::Color::White);
  collect25.setOrigin(collect25.getOrigin().x+collect25.getLocalBounds().width/2, collect25.getOrigin().y+collect25.getLocalBounds().height/2);
  collect25.setPosition(sizeX/2*0.65, sizeY/2*0.25);

  collect26.setFillColor(sf::Color::White);
  collect26.setOrigin(collect26.getOrigin().x+collect26.getLocalBounds().width/2, collect26.getOrigin().y+collect26.getLocalBounds().height/2);
  collect26.setPosition(sizeX/2*1.34, sizeY/2*0.25);

  collect27.setFillColor(sf::Color::White);
  collect27.setOrigin(collect27.getOrigin().x+collect27.getLocalBounds().width/2, collect27.getOrigin().y+collect27.getLocalBounds().height/2);
  collect27.setPosition(sizeX/2*0.45, sizeY/2*0.58);

  collect28.setFillColor(sf::Color::White);
  collect28.setOrigin(collect28.getOrigin().x+collect28.getLocalBounds().width/2, collect28.getOrigin().y+collect28.getLocalBounds().height/2);
  collect28.setPosition(sizeX/2*0.55, sizeY/2*0.58);

  collect29.setFillColor(sf::Color::White);
  collect29.setOrigin(collect29.getOrigin().x+collect29.getLocalBounds().width/2, collect29.getOrigin().y+collect29.getLocalBounds().height/2);
  collect29.setPosition(sizeX/2*0.65, sizeY/2*0.58);

  collect30.setFillColor(sf::Color::White);
  collect30.setOrigin(collect30.getOrigin().x+collect30.getLocalBounds().width/2, collect30.getOrigin().y+collect30.getLocalBounds().height/2);
  collect30.setPosition(sizeX/2*0.77, sizeY/2*0.58);

  collect31.setFillColor(sf::Color::White);
  collect31.setOrigin(collect31.getOrigin().x+collect31.getLocalBounds().width/2, collect31.getOrigin().y+collect31.getLocalBounds().height/2);
  collect31.setPosition(sizeX/2*0.93, sizeY/2*0.58);

  collect32.setFillColor(sf::Color::White);
  collect32.setOrigin(collect32.getOrigin().x+collect32.getLocalBounds().width/2, collect32.getOrigin().y+collect32.getLocalBounds().height/2);
  collect32.setPosition(sizeX/2*1.07, sizeY/2*0.58);

  collect33.setFillColor(sf::Color::White);
  collect33.setOrigin(collect33.getOrigin().x+collect33.getLocalBounds().width/2, collect33.getOrigin().y+collect33.getLocalBounds().height/2);
  collect33.setPosition(sizeX/2*1.21, sizeY/2*0.58);

  collect34.setFillColor(sf::Color::White);
  collect34.setOrigin(collect34.getOrigin().x+collect34.getLocalBounds().width/2, collect34.getOrigin().y+collect34.getLocalBounds().height/2);
  collect34.setPosition(sizeX/2*1.33, sizeY/2*0.58);

  collect35.setFillColor(sf::Color::White);
  collect35.setOrigin(collect35.getOrigin().x+collect35.getLocalBounds().width/2, collect35.getOrigin().y+collect35.getLocalBounds().height/2);
  collect35.setPosition(sizeX/2*1.43, sizeY/2*0.58);

  collect36.setFillColor(sf::Color::White);
  collect36.setOrigin(collect36.getOrigin().x+collect36.getLocalBounds().width/2, collect36.getOrigin().y+collect36.getLocalBounds().height/2);
  collect36.setPosition(sizeX/2*1.55, sizeY/2*0.58);

  collect37.setFillColor(sf::Color::White);
  collect37.setOrigin(collect37.getOrigin().x+collect37.getLocalBounds().width/2, collect37.getOrigin().y+collect37.getLocalBounds().height/2);
  collect37.setPosition(sizeX/2*0.45, sizeY/2*0.77);

  collect38.setFillColor(sf::Color::White);
  collect38.setOrigin(collect38.getOrigin().x+collect38.getLocalBounds().width/2, collect38.getOrigin().y+collect38.getLocalBounds().height/2);
  collect38.setPosition(sizeX/2*0.65, sizeY/2*0.77);

  collect39.setFillColor(sf::Color::White);
  collect39.setOrigin(collect39.getOrigin().x+collect39.getLocalBounds().width/2, collect39.getOrigin().y+collect39.getLocalBounds().height/2);
  collect39.setPosition(sizeX/2*0.77, sizeY/2*0.77);

  collect40.setFillColor(sf::Color::White);
  collect40.setOrigin(collect40.getOrigin().x+collect40.getLocalBounds().width/2, collect40.getOrigin().y+collect40.getLocalBounds().height/2);
  collect40.setPosition(sizeX/2*0.88, sizeY/2*0.77);

  collect41.setFillColor(sf::Color::White);
  collect41.setOrigin(collect41.getOrigin().x+collect41.getLocalBounds().width/2, collect41.getOrigin().y+collect41.getLocalBounds().height/2);
  collect41.setPosition(sizeX/2*0.99, sizeY/2*0.77);

  collect42.setFillColor(sf::Color::White);
  collect42.setOrigin(collect42.getOrigin().x+collect42.getLocalBounds().width/2, collect42.getOrigin().y+collect42.getLocalBounds().height/2);
  collect42.setPosition(sizeX/2*1.1, sizeY/2*0.77);

  collect43.setFillColor(sf::Color::White);
  collect43.setOrigin(collect43.getOrigin().x+collect43.getLocalBounds().width/2, collect43.getOrigin().y+collect43.getLocalBounds().height/2);
  collect43.setPosition(sizeX/2*1.21, sizeY/2*0.77);

  collect44.setFillColor(sf::Color::White);
  collect44.setOrigin(collect44.getOrigin().x+collect44.getLocalBounds().width/2, collect44.getOrigin().y+collect44.getLocalBounds().height/2);
  collect44.setPosition(sizeX/2*1.33, sizeY/2*0.77);

  collect45.setFillColor(sf::Color::White);
  collect45.setOrigin(collect45.getOrigin().x+collect45.getLocalBounds().width/2, collect45.getOrigin().y+collect45.getLocalBounds().height/2);
  collect45.setPosition(sizeX/2*1.55, sizeY/2*0.77);

  collect46.setFillColor(sf::Color::White);
  collect46.setOrigin(collect46.getOrigin().x+collect46.getLocalBounds().width/2, collect46.getOrigin().y+collect46.getLocalBounds().height/2);
  collect46.setPosition(sizeX/2*0.45, sizeY/2*0.93);

  collect47.setFillColor(sf::Color::White);
  collect47.setOrigin(collect47.getOrigin().x+collect47.getLocalBounds().width/2, collect47.getOrigin().y+collect47.getLocalBounds().height/2);
  collect47.setPosition(sizeX/2*0.55, sizeY/2*0.93);

  collect48.setFillColor(sf::Color::White);
  collect48.setOrigin(collect48.getOrigin().x+collect48.getLocalBounds().width/2, collect48.getOrigin().y+collect48.getLocalBounds().height/2);
  collect48.setPosition(sizeX/2*0.65, sizeY/2*0.93);

  collect49.setFillColor(sf::Color::White);
  collect49.setOrigin(collect49.getOrigin().x+collect49.getLocalBounds().width/2, collect49.getOrigin().y+collect49.getLocalBounds().height/2);
  collect49.setPosition(sizeX/2*0.77, sizeY/2*0.93);

  collect50.setFillColor(sf::Color::White);
  collect50.setOrigin(collect50.getOrigin().x+collect50.getLocalBounds().width/2, collect50.getOrigin().y+collect50.getLocalBounds().height/2);
  collect50.setPosition(sizeX/2*1.22, sizeY/2*0.93);

  collect51.setFillColor(sf::Color::White);
  collect51.setOrigin(collect51.getOrigin().x+collect51.getLocalBounds().width/2, collect51.getOrigin().y+collect51.getLocalBounds().height/2);
  collect51.setPosition(sizeX/2*1.33, sizeY/2*0.93);

  collect52.setFillColor(sf::Color::White);
  collect52.setOrigin(collect52.getOrigin().x+collect52.getLocalBounds().width/2, collect52.getOrigin().y+collect52.getLocalBounds().height/2);
  collect52.setPosition(sizeX/2*1.43, sizeY/2*0.93);

  collect53.setFillColor(sf::Color::White);
  collect53.setOrigin(collect53.getOrigin().x+collect53.getLocalBounds().width/2, collect53.getOrigin().y+collect53.getLocalBounds().height/2);
  collect53.setPosition(sizeX/2*1.55, sizeY/2*0.93);

  collect54.setFillColor(sf::Color::White);
  collect54.setOrigin(collect54.getOrigin().x+collect54.getLocalBounds().width/2, collect54.getOrigin().y+collect54.getLocalBounds().height/2);
  collect54.setPosition(sizeX/2*0.45, sizeY/2*1.12);

  collect55.setFillColor(sf::Color::White);
  collect55.setOrigin(collect55.getOrigin().x+collect55.getLocalBounds().width/2, collect55.getOrigin().y+collect55.getLocalBounds().height/2);
  collect55.setPosition(sizeX/2*0.54, sizeY/2*1.12);

  collect56.setFillColor(sf::Color::White);
  collect56.setOrigin(collect56.getOrigin().x+collect56.getLocalBounds().width/2, collect56.getOrigin().y+collect56.getLocalBounds().height/2);
  collect56.setPosition(sizeX/2*0.65, sizeY/2*1.12);

  collect57.setFillColor(sf::Color::White);
  collect57.setOrigin(collect57.getOrigin().x+collect57.getLocalBounds().width/2, collect57.getOrigin().y+collect57.getLocalBounds().height/2);
  collect57.setPosition(sizeX/2*0.77, sizeY/2*1.12);

  collect58.setFillColor(sf::Color::White);
  collect58.setOrigin(collect58.getOrigin().x+collect58.getLocalBounds().width/2, collect58.getOrigin().y+collect58.getLocalBounds().height/2);
  collect58.setPosition(sizeX/2*0.88, sizeY/2*1.12);

  collect59.setFillColor(sf::Color::White);
  collect59.setOrigin(collect59.getOrigin().x+collect59.getLocalBounds().width/2, collect59.getOrigin().y+collect59.getLocalBounds().height/2);
  collect59.setPosition(sizeX/2*0.99, sizeY/2*1.12);

  collect60.setFillColor(sf::Color::White);
  collect60.setOrigin(collect60.getOrigin().x+collect60.getLocalBounds().width/2, collect60.getOrigin().y+collect60.getLocalBounds().height/2);
  collect60.setPosition(sizeX/2*1.1, sizeY/2*1.12);

  collect61.setFillColor(sf::Color::White);
  collect61.setOrigin(collect61.getOrigin().x+collect61.getLocalBounds().width/2, collect61.getOrigin().y+collect61.getLocalBounds().height/2);
  collect61.setPosition(sizeX/2*1.22, sizeY/2*1.12);

  collect62.setFillColor(sf::Color::White);
  collect62.setOrigin(collect62.getOrigin().x+collect62.getLocalBounds().width/2, collect62.getOrigin().y+collect62.getLocalBounds().height/2);
  collect62.setPosition(sizeX/2*1.33, sizeY/2*1.12);

  collect63.setFillColor(sf::Color::White);
  collect63.setOrigin(collect63.getOrigin().x+collect63.getLocalBounds().width/2, collect63.getOrigin().y+collect63.getLocalBounds().height/2);
  collect63.setPosition(sizeX/2*1.45, sizeY/2*1.12);

  collect64.setFillColor(sf::Color::White);
  collect64.setOrigin(collect64.getOrigin().x+collect64.getLocalBounds().width/2, collect64.getOrigin().y+collect64.getLocalBounds().height/2);
  collect64.setPosition(sizeX/2*1.55, sizeY/2*1.12);

  collect65.setFillColor(sf::Color::White);
  collect65.setOrigin(collect65.getOrigin().x+collect65.getLocalBounds().width/2, collect65.getOrigin().y+collect65.getLocalBounds().height/2);
  collect65.setPosition(sizeX/2*0.45, sizeY/2*1.3);

  collect66.setFillColor(sf::Color::White);
  collect66.setOrigin(collect66.getOrigin().x+collect66.getLocalBounds().width/2, collect66.getOrigin().y+collect66.getLocalBounds().height/2);
  collect66.setPosition(sizeX/2*0.54, sizeY/2*1.3);

  collect67.setFillColor(sf::Color::White);
  collect67.setOrigin(collect67.getOrigin().x+collect67.getLocalBounds().width/2, collect67.getOrigin().y+collect67.getLocalBounds().height/2);
  collect67.setPosition(sizeX/2*0.65, sizeY/2*1.3);

  collect68.setFillColor(sf::Color::White);
  collect68.setOrigin(collect68.getOrigin().x+collect68.getLocalBounds().width/2, collect68.getOrigin().y+collect68.getLocalBounds().height/2);
  collect68.setPosition(sizeX/2*0.77, sizeY/2*1.3);

  collect69.setFillColor(sf::Color::White);
  collect69.setOrigin(collect69.getOrigin().x+collect69.getLocalBounds().width/2, collect69.getOrigin().y+collect69.getLocalBounds().height/2);
  collect69.setPosition(sizeX/2*0.93, sizeY/2*1.3);

  collect70.setFillColor(sf::Color::White);
  collect70.setOrigin(collect70.getOrigin().x+collect70.getLocalBounds().width/2, collect70.getOrigin().y+collect70.getLocalBounds().height/2);
  collect70.setPosition(sizeX/2*1.05, sizeY/2*1.3);

  collect71.setFillColor(sf::Color::White);
  collect71.setOrigin(collect71.getOrigin().x+collect71.getLocalBounds().width/2, collect71.getOrigin().y+collect71.getLocalBounds().height/2);
  collect71.setPosition(sizeX/2*1.17, sizeY/2*1.3);

  collect72.setFillColor(sf::Color::White);
  collect72.setOrigin(collect72.getOrigin().x+collect72.getLocalBounds().width/2, collect72.getOrigin().y+collect72.getLocalBounds().height/2);
  collect72.setPosition(sizeX/2*1.29, sizeY/2*1.3);

  collect73.setFillColor(sf::Color::White);
  collect73.setOrigin(collect73.getOrigin().x+collect73.getLocalBounds().width/2, collect73.getOrigin().y+collect73.getLocalBounds().height/2);
  collect73.setPosition(sizeX/2*1.41, sizeY/2*1.3);

  collect74.setFillColor(sf::Color::White);
  collect74.setOrigin(collect74.getOrigin().x+collect74.getLocalBounds().width/2, collect74.getOrigin().y+collect74.getLocalBounds().height/2);
  collect74.setPosition(sizeX/2*1.55, sizeY/2*1.3);

  collect75.setFillColor(sf::Color::White);
  collect75.setOrigin(collect75.getOrigin().x+collect75.getLocalBounds().width/2, collect75.getOrigin().y+collect75.getLocalBounds().height/2);
  collect75.setPosition(sizeX/2*0.45, sizeY/2*1.5);

  collect76.setFillColor(sf::Color::White);
  collect76.setOrigin(collect76.getOrigin().x+collect76.getLocalBounds().width/2, collect76.getOrigin().y+collect76.getLocalBounds().height/2);
  collect76.setPosition(sizeX/2*0.54, sizeY/2*1.5);

  collect77.setFillColor(sf::Color::White);
  collect77.setOrigin(collect77.getOrigin().x+collect77.getLocalBounds().width/2, collect77.getOrigin().y+collect77.getLocalBounds().height/2);
  collect77.setPosition(sizeX/2*0.65, sizeY/2*1.5);

  collect78.setFillColor(sf::Color::White);
  collect78.setOrigin(collect78.getOrigin().x+collect78.getLocalBounds().width/2, collect78.getOrigin().y+collect78.getLocalBounds().height/2);
  collect78.setPosition(sizeX/2*0.77, sizeY/2*1.5);

  collect79.setFillColor(sf::Color::White);
  collect79.setOrigin(collect79.getOrigin().x+collect79.getLocalBounds().width/2, collect79.getOrigin().y+collect79.getLocalBounds().height/2);
  collect79.setPosition(sizeX/2*0.89, sizeY/2*1.5);

  collect80.setFillColor(sf::Color::White);
  collect80.setOrigin(collect80.getOrigin().x+collect80.getLocalBounds().width/2, collect80.getOrigin().y+collect80.getLocalBounds().height/2);
  collect80.setPosition(sizeX/2*1.01, sizeY/2*1.5);

  collect81.setFillColor(sf::Color::White);
  collect81.setOrigin(collect81.getOrigin().x+collect81.getLocalBounds().width/2, collect81.getOrigin().y+collect81.getLocalBounds().height/2);
  collect81.setPosition(sizeX/2*1.13, sizeY/2*1.5);

  collect82.setFillColor(sf::Color::White);
  collect82.setOrigin(collect82.getOrigin().x+collect82.getLocalBounds().width/2, collect82.getOrigin().y+collect82.getLocalBounds().height/2);
  collect82.setPosition(sizeX/2*1.25, sizeY/2*1.5);

  collect83.setFillColor(sf::Color::White);
  collect83.setOrigin(collect83.getOrigin().x+collect83.getLocalBounds().width/2, collect83.getOrigin().y+collect83.getLocalBounds().height/2);
  collect83.setPosition(sizeX/2*1.45, sizeY/2*1.5);

  collect84.setFillColor(sf::Color::White);
  collect84.setOrigin(collect84.getOrigin().x+collect84.getLocalBounds().width/2, collect84.getOrigin().y+collect84.getLocalBounds().height/2);
  collect84.setPosition(sizeX/2*1.55, sizeY/2*1.5);

  collect85.setFillColor(sf::Color::White);
  collect85.setOrigin(collect85.getOrigin().x+collect85.getLocalBounds().width/2, collect85.getOrigin().y+collect85.getLocalBounds().height/2);
  collect85.setPosition(sizeX/2*0.45, sizeY/2*1.7);

  collect86.setFillColor(sf::Color::White);
  collect86.setOrigin(collect86.getOrigin().x+collect86.getLocalBounds().width/2, collect86.getOrigin().y+collect86.getLocalBounds().height/2);
  collect86.setPosition(sizeX/2*0.55, sizeY/2*1.7);

  collect87.setFillColor(sf::Color::White);
  collect87.setOrigin(collect87.getOrigin().x+collect87.getLocalBounds().width/2, collect87.getOrigin().y+collect87.getLocalBounds().height/2);
  collect87.setPosition(sizeX/2*0.65, sizeY/2*1.7);

  collect88.setFillColor(sf::Color::White);
  collect88.setOrigin(collect88.getOrigin().x+collect88.getLocalBounds().width/2, collect88.getOrigin().y+collect88.getLocalBounds().height/2);
  collect88.setPosition(sizeX/2*0.77, sizeY/2*1.7);

  collect89.setFillColor(sf::Color::White);
  collect89.setOrigin(collect89.getOrigin().x+collect89.getLocalBounds().width/2, collect89.getOrigin().y+collect89.getLocalBounds().height/2);
  collect89.setPosition(sizeX/2*0.94, sizeY/2*1.7);

  collect90.setFillColor(sf::Color::White);
  collect90.setOrigin(collect90.getOrigin().x+collect90.getLocalBounds().width/2, collect90.getOrigin().y+collect90.getLocalBounds().height/2);
  collect90.setPosition(sizeX/2*1.06, sizeY/2*1.7);

  collect91.setFillColor(sf::Color::White);
  collect91.setOrigin(collect91.getOrigin().x+collect91.getLocalBounds().width/2, collect91.getOrigin().y+collect91.getLocalBounds().height/2);
  collect91.setPosition(sizeX/2*1.22, sizeY/2*1.7);

  collect92.setFillColor(sf::Color::White);
  collect92.setOrigin(collect92.getOrigin().x+collect92.getLocalBounds().width/2, collect92.getOrigin().y+collect92.getLocalBounds().height/2);
  collect92.setPosition(sizeX/2*1.34, sizeY/2*1.7);

  collect93.setFillColor(sf::Color::White);
  collect93.setOrigin(collect93.getOrigin().x+collect93.getLocalBounds().width/2, collect93.getOrigin().y+collect93.getLocalBounds().height/2);
  collect93.setPosition(sizeX/2*1.44, sizeY/2*1.7);

  collect94.setFillColor(sf::Color::White);
  collect94.setOrigin(collect94.getOrigin().x+collect94.getLocalBounds().width/2, collect94.getOrigin().y+collect94.getLocalBounds().height/2);
  collect94.setPosition(sizeX/2*1.55, sizeY/2*1.7);

  collect95.setFillColor(sf::Color::White);
  collect95.setOrigin(collect95.getOrigin().x+collect95.getLocalBounds().width/2, collect95.getOrigin().y+collect95.getLocalBounds().height/2);
  collect95.setPosition(sizeX/2*0.45, sizeY/2*1.9);

  collect96.setFillColor(sf::Color::White);
  collect96.setOrigin(collect96.getOrigin().x+collect96.getLocalBounds().width/2, collect96.getOrigin().y+collect96.getLocalBounds().height/2);
  collect96.setPosition(sizeX/2*0.57, sizeY/2*1.9);

  collect97.setFillColor(sf::Color::White);
  collect97.setOrigin(collect97.getOrigin().x+collect97.getLocalBounds().width/2, collect97.getOrigin().y+collect97.getLocalBounds().height/2);
  collect97.setPosition(sizeX/2*0.69, sizeY/2*1.9);

  collect98.setFillColor(sf::Color::White);
  collect98.setOrigin(collect98.getOrigin().x+collect98.getLocalBounds().width/2, collect98.getOrigin().y+collect98.getLocalBounds().height/2);
  collect98.setPosition(sizeX/2*0.81, sizeY/2*1.9);

  collect99.setFillColor(sf::Color::White);
  collect99.setOrigin(collect99.getOrigin().x+collect99.getLocalBounds().width/2, collect99.getOrigin().y+collect99.getLocalBounds().height/2);
  collect99.setPosition(sizeX/2*0.93, sizeY/2*1.9);

  collect100.setFillColor(sf::Color::White);
  collect100.setOrigin(collect100.getOrigin().x+collect100.getLocalBounds().width/2, collect100.getOrigin().y+collect100.getLocalBounds().height/2);
  collect100.setPosition(sizeX/2*1.05, sizeY/2*1.9);

  collect101.setFillColor(sf::Color::White);
  collect101.setOrigin(collect101.getOrigin().x+collect101.getLocalBounds().width/2, collect101.getOrigin().y+collect101.getLocalBounds().height/2);
  collect101.setPosition(sizeX/2*1.17, sizeY/2*1.9);

  collect102.setFillColor(sf::Color::White);
  collect102.setOrigin(collect102.getOrigin().x+collect102.getLocalBounds().width/2, collect102.getOrigin().y+collect102.getLocalBounds().height/2);
  collect102.setPosition(sizeX/2*1.29, sizeY/2*1.9);

  collect103.setFillColor(sf::Color::White);
  collect103.setOrigin(collect103.getOrigin().x+collect103.getLocalBounds().width/2, collect103.getOrigin().y+collect103.getLocalBounds().height/2);
  collect103.setPosition(sizeX/2*1.41, sizeY/2*1.9);

  collect104.setFillColor(sf::Color::White);
  collect104.setOrigin(collect104.getOrigin().x+collect104.getLocalBounds().width/2, collect104.getOrigin().y+collect104.getLocalBounds().height/2);
  collect104.setPosition(sizeX/2*1.55, sizeY/2*1.9);

  collects.push_back(collect1);
  collects.push_back(collect2);
  collects.push_back(collect3);
  collects.push_back(collect4);
  collects.push_back(collect5);
  collects.push_back(collect6);
  collects.push_back(collect7);
  collects.push_back(collect8);
  collects.push_back(collect9);
  collects.push_back(collect10);
  collects.push_back(collect11);
  collects.push_back(collect12);
  collects.push_back(collect13);
  collects.push_back(collect14);
  collects.push_back(collect15);
  collects.push_back(collect16);
  collects.push_back(collect17);
  collects.push_back(collect18);
  collects.push_back(collect19);
  collects.push_back(collect20);
  collects.push_back(collect21);
  collects.push_back(collect22);
  collects.push_back(collect23);
  collects.push_back(collect24);
  collects.push_back(collect25);
  collects.push_back(collect26);
  collects.push_back(collect27);
  collects.push_back(collect28);
  collects.push_back(collect29);
  collects.push_back(collect30);
  collects.push_back(collect31);
  collects.push_back(collect32);
  collects.push_back(collect33);
  collects.push_back(collect34);
  collects.push_back(collect35);
  collects.push_back(collect36);
  collects.push_back(collect37);
  collects.push_back(collect38);
  collects.push_back(collect39);
  collects.push_back(collect40);
  collects.push_back(collect41);
  collects.push_back(collect42);
  collects.push_back(collect43);
  collects.push_back(collect44);
  collects.push_back(collect45);
  collects.push_back(collect46);
  collects.push_back(collect47);
  collects.push_back(collect48);
  collects.push_back(collect49);
  collects.push_back(collect50);
  collects.push_back(collect51);
  collects.push_back(collect52);
  collects.push_back(collect53);
  collects.push_back(collect54);
  collects.push_back(collect55);
  collects.push_back(collect56);
  collects.push_back(collect57);
  collects.push_back(collect58);
  collects.push_back(collect59);
  collects.push_back(collect60);
  collects.push_back(collect61);
  collects.push_back(collect62);
  collects.push_back(collect63);
  collects.push_back(collect64);
  collects.push_back(collect65);
  collects.push_back(collect66);
  collects.push_back(collect67);
  collects.push_back(collect68);
  collects.push_back(collect69);
  collects.push_back(collect70);
  collects.push_back(collect71);
  collects.push_back(collect72);
  collects.push_back(collect73);
  collects.push_back(collect74);
  collects.push_back(collect75);
  collects.push_back(collect76);
  collects.push_back(collect77);
  collects.push_back(collect78);
  collects.push_back(collect79);
  collects.push_back(collect80);
  collects.push_back(collect81);
  collects.push_back(collect82);
  collects.push_back(collect83);
  collects.push_back(collect84);
  collects.push_back(collect85);
  collects.push_back(collect86);
  collects.push_back(collect87);
  collects.push_back(collect88);
  collects.push_back(collect89);
  collects.push_back(collect90);
  collects.push_back(collect91);
  collects.push_back(collect92);
  collects.push_back(collect93);
  collects.push_back(collect94);
  collects.push_back(collect95);
  collects.push_back(collect96);
  collects.push_back(collect97);
  collects.push_back(collect98);
  collects.push_back(collect99);
  collects.push_back(collect100);
  collects.push_back(collect101);
  collects.push_back(collect102);
  collects.push_back(collect103);
  collects.push_back(collect104);
  return collects;
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
