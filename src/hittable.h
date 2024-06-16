#ifndef HITTABLE_H
#define HITTABLE_H

class hit_record {
public:
  point3 p;
  vec3 normal;
  double t;
  bool front_face;

  void set_face_normal(const ray &r, const vec3 &outward_normal) {
    // Sets the hit record normal vector.
    // NOTE: the parameter `outward_normal` is assumed to have unit length.

    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class hittable {
public:
  // Virtual destructor for proper cleanup of derived classes
  virtual ~hittable() = default;
  // Pure virtual function (abstract function)
  virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;
};

#endif