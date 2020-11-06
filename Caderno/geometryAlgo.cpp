double polygonArea(vetor p[], int n){
    double area = 0;
    //We will triangulate the polygon
    //into triangles with points p[0],p[i],p[i+1]

    for(int i = 0; i < N; i++){
        int x1 = p[i][0] - p[0][0];
        int y1 = p[i][1] - p[0][1];
        int x2 = p[i+1][0] - p[0][0];
        int y2 = p[i+1][1] - p[0][1];
        int cross = x1y2 - x2y1;
        area += cross;
    }
    
    return abs(area/2)
}