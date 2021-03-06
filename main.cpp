#include "geohash.h"

//g++ -o Test geohash.cpp main.cpp
int main()
{
	CGeoHash m_GeoHash;
	
	printf("[main]geohash1=%s.\n", m_GeoHash.Encode(39.928167, 116.389550, 20));
	//printf("[main]geohash2=%s.\n", m_GeoHash.Get_GeoHash_String(39.928167, 116.389540));
	//printf("[main]geohash3=%s.\n", m_GeoHash.Get_GeoHash_String(39.928177, 116.389550));86.86385
	
	_Geo_Rect obj_Geo_Rect = m_GeoHash.GetGeoRect(39.928167, 116.389550, 20);
	printf("[main]m_dMinLatitude=%f, m_dMaxLatitude=%f.\n", obj_Geo_Rect.m_dMinLatitude, obj_Geo_Rect.m_dMaxLatitude);
	printf("[main]m_dMinLongitude=%f, m_dMaxLongitude=%f.\n", obj_Geo_Rect.m_dMinLongitude, obj_Geo_Rect.m_dMaxLongitude);
	
	_Geo_Neighbors obj_Geo_Neighbors;
	obj_Geo_Neighbors = m_GeoHash.GetNeighbors(39.928167, 116.389550, 20);
	printf("[main]Neighbors(");
	for(int i= 0; i < 9; i ++)
	{
		printf("%s,", obj_Geo_Neighbors.m_szNerghbors[i]);
	}	
	printf(");\n");
	
	obj_Geo_Rect.m_dMinLatitude  = 44.1839;
	obj_Geo_Rect.m_dMinLongitude = 86.86385;
	obj_Geo_Rect.m_dMaxLatitude  = 44.18356;
	obj_Geo_Rect.m_dMaxLongitude = 86.86372;
	
	double dDistance = m_GeoHash.GetDistance(obj_Geo_Rect.m_dMinLatitude, obj_Geo_Rect.m_dMinLongitude, 
																					 obj_Geo_Rect.m_dMaxLatitude, obj_Geo_Rect.m_dMaxLongitude);
	printf("[main]distance=%f.\n", dDistance);
	return 0;
}
