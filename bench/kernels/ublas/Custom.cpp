/*
 custom kernel
*/

namespace boost {
    
double custom(size_t N, size_t iterations = 1){
/*
    boost::numeric::ublas::matrix<double> a(N, N), b(N, N), c(N, N);
    
    minit(a.size1(), a);
    minit(b.size1(), b);
*/
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        
        //place custom code here
        
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    /*
     // check to see if nothing happened during run to invalidate the times
     if(tmin*(1.0 + deviation*0.01) < tavg){
     std::cerr << "uBLAS kernel 'custom': Time deviation too large!!!" << std::endl;
     }
     */
    return tavg;
    
}

}