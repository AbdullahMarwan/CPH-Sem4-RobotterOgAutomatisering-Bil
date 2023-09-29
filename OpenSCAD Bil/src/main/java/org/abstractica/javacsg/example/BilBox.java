package org.abstractica.javacsg.example;

import org.abstractica.javacsg.*;


public class BilBox
{
	public static void main(String[] args)
	{
		JavaCSG csg = JavaCSGFactory.createDefault();
		Geometry3D box = csg.box3D(130, 45, 20, false);
		Geometry3D cutoutBox = csg.box3D(120, 35, 22, false);
//		Geometry3D cylinder = csg.cylinder3D(10, 40, 32, true);
		Geometry3D diff = csg.difference3D(box, cutoutBox);
		csg.view(csg.cache(diff));

		System.out.println(diff.getMin());
		System.out.println(diff.getMax());
	}
}
