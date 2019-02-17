/* Increased diameter actuator for Happ Super joystick, to better hit diagonals.
 *
 * The original Happ Super joystick actuator can be flipped to switch between
 * 4-way and 8-way (e.g. the 8-way side has a bigger diameter). This version
 * adds 4mm to the 8-way side diameter, while increasing the 4-way diameter to
 * be that of the original 8-way side.
 *
 * Author: @lluismh
 *
 * This work is licensed under a Creative Commons Attribution-ShareAlike 4.0
 * International License.
 */

hole_radius = 5.30;

middle_part_radius = 7.15;
middle_part_height = 4;

wide_part_min_radius = 9.40;
wide_part_max_radius = 10.90;
wide_part_height = 7.80;

narrow_part_min_radius = 7.90;
narrow_part_max_radius = 9.90;
narrow_part_height = 7.70;

rotate_extrude($fn=200) polygon(points = [[hole_radius, 0], [ wide_part_max_radius, 0], [wide_part_min_radius, wide_part_height], [middle_part_radius, wide_part_height], [middle_part_radius, wide_part_height + middle_part_height], [narrow_part_min_radius, wide_part_height + middle_part_height], [narrow_part_max_radius, wide_part_height + middle_part_height + narrow_part_height], [hole_radius, wide_part_height + middle_part_height + narrow_part_height]]);
