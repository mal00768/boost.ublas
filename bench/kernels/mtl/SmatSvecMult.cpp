/*
 spare matrix and sparse vector multiplication kernel
*/

namespace mtl {
    
double smatsvecmult(size_t N, size_t iterations = 1) {
    
    mtl::compressed2D<double> a(N, N);
    mtl::dense_vector<double> b(N), c(N); // sparse not fully implemented yet
    
    sminit(N, a);
    vinit(N, b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        c = a * b;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    /*
     // check to see if nothing happened during rum to invalidate the times
     if(tmin*(1.0 + deviation*0.01) < tavg){
     std::cerr << "uBLAS kernel 'smatsvecmult': Time deviation too large!!!" << std::endl;
     }
     */
    return tavg;
    
}

}