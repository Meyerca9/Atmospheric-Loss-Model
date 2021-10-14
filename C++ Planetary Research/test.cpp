#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main() {
    double Mp,m_imp,Vimp,rho,h,R,impactor_bulk_density,r,pi,M_atmos,r_cap,Mcap_tangent,
    new_atmos,cap_factor,mcap_ratio,m_min,m_max,r_min,m_eject,theta;

    impactor_bulk_density =  2.0; // g/cm^2
    pi =  3.1415926535897;
   
    // Mp = mass of planet (kg)
    // m_imp = mass of impactor (kg)
    // Vimp = impact velocity (m/s)
    // rho = planetesimals atmospheric density at the ground (g/cm^3)
    // h = atmospheric scale height (km)
    // R = planetary radius (km)
    // r = impactor radius (km)
    // M_atmos = Mass of the Atmosphere (kg)
    // r_cap = impactor radius needed in order to eject the whole cap
    // Mcap_tangent
    // new_atmos
    // cap_factor
    // mcap_ratio
    // m_min
    // m_max
    // r_min
    // m_eject = mass that is ejected above the tangent line
    

    std::cout <<"Enter the planets mass";
    std::cin >> Mp;

    std::cout <<"Enter the planets radius";
    std::cin >> R;

    std::cout <<"Enter the Mass of the Atmosphere";
    std::cin >> M_atmos;

    std::cout <<"Enter the impactors mass";
    std::cin >> m_imp;

    std::cout <<"Enter the impact velocity";
    std::cin >> Vimp;

    std::cout <<"Enter the impactor radius";
    std::cin >> r;

    std::cout <<"Enter planetesimals atmospheric density at the ground";
    std::cin >> rho;

    std::cout <<"Enter the atmospheric scale height";
    std::cin >> h;

    std::cout <<"Enter the impact angle";
    std::cin >> theta;

    
    cap_factor = sqrt((pi*R)/(2*h)); // Impactor mass needed to eject all the atmospheric mass for planetesimals
    Mcap_tangent = ((2*pi)*(rho)*(h*h)*(R)); // maximum atmospheric mass that a single planetesimal impact can eject above the tangent plane
    mcap_ratio = sqrt((pi*h)/(8*R)); // impactor mass needed to eject all the atmospheric mass above tangent plane if impact veloity is comparable to escape velocity 
    m_min = 4*pi*rho*pow(h,3); // minimum mass needed in order to eject any atmosphere
    m_max = sqrt(2)*rho*pow((pi*h*R),3.0/2.0); // masses greater than this are able to eject all mass above the tangent line which is h/2r of the atmosphere
    r_min = pow(((3*rho)/impactor_bulk_density), 1.0 / 3.0)*h; // if impactor is less than r_min no mass is ejected
    r_cap = pow(((3*sqrt(2*pi)*rho)/(4*impactor_bulk_density)), 1.0/3.0)*sqrt(h*R); // impactor radius needed in order to eject entire cap


    std::cout << r_min<<endl;
    std::cout << r_cap<<endl;
    std::cout << m_min<<endl;
    std::cout << m_max<<endl;
    std::cout << m_max<<endl;


    if (m_imp < m_min){ // if impactor mass is smaller that mass required to eject any atmosphere
        m_eject = 0;
        std::cout << m_eject<<endl;
        return 0;
    }


    if (r < r_min){ // if impactor radius is smaller than radius required to eject any atmosphere
        m_eject =0;
        std::cout <<m_eject<<endl;
        return 0;
    }

    // if pi/2 - theta >> sqrt(h/R)
    if ((pi/2) - theta > sqrt(h/R)){
        if (r_min < r < r_cap && m_min < m_imp < m_max){  // if impactor size and mass are inbetween values for max eject and no eject
            m_eject = ((pow(sin(theta), 2)*(cos(theta)))/(2))*m_imp; // for theta = 0, m_imp = (4 pi rho h^3)
            std::cout << m_eject<<endl;
        
        }
    }
   // if pi/2 - theta << sqrt(h/R)

    if (r_min < r < r_cap && m_min < m_imp < m_max){
        m_eject = (r_min/(2*r))*(1-pow((r_min/r),2));
        std::cout << m_eject<<endl;
     }

    if (m_imp > m_max && r >= r_cap){ //  impactor mass and radius needed in order to eject all the mass above the tangent plane
        m_eject = (h/(2*r));
        std::cout << m_eject<<endl;   
    }





}
    

    
