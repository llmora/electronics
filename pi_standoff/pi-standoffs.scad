pi_mounting_hole_diameter = 3;
pi_standoff_height = 7;
pi_standoff_diameter = 7.5;

$fn = 200;

difference() {

  linear_extrude(height = pi_standoff_height) {
    circle(r=pi_standoff_diameter/2);
  }


  linear_extrude(height = pi_standoff_height) {
    circle(r=pi_mounting_hole_diameter/2);
  }

}
