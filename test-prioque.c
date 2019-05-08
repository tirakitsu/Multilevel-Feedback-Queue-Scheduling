

// comparison function for queue of SomeType elements
int some_type_compare(void *e1, void *e2) {
  SomeType *s1=(SomeType *)e1;
  SomeType *s2=(SomeType *)e2;
  if (s1->a == s2->a && !strcmp(s1->buf, s2->buf)) {
    return 0;
  }
  else {
    return 1;
  }
}

int main(int argc, char *argv[]) {
  Queue q;
  SomeType s1, s2, s3, s4, e;
  
  s1.a=5;
  strcpy(s1.buf, "hello");
  s2.a=7;
  strcpy(s2.buf, "yo");
  s3.a=3;
  strcpy(s3.buf, "hola");
  s4.a=5;
  strcpy(s4.buf, "whereyat");

  init_queue(&q,
	     sizeof(SomeType),
	     FALSE /* don't allow duplicates, which exercises the
		      comparison function */,
	     some_type_compare,
	     FALSE);

  add_to_queue(&q, &s1, s1.a+1);
  add_to_queue(&q, &s2, s2.a+1);

  // test duplicate detection
  add_to_queue(&q, &s3, s3.a+1);
  add_to_queue(&q, &s3, s3.a+1);  // duplicate, should be rejected
  add_to_queue(&q, &s3, s3.a+1);  // duplicate, should be rejected

  add_to_queue(&q, &s4, s4.a+1);
  rewind_queue(&q);
  printf("Queue contains:\n");
  while (! end_of_queue(&q)) {
    printf("%d %s with priority %d\n", 
	   ((SomeType *)pointer_to_current(&q))->a,
	   ((SomeType *)pointer_to_current(&q))->buf,
	   current_priority(&q));
    next_element(&q);
  }
  remove_from_front(&q, &e);
  printf("Removed %d %s from queue.\n", e.a, e.buf);
  printf("Queue contains:\n");
  while (! end_of_queue(&q)) {
    printf("%d %s with priority %d\n", 
	   ((SomeType *)pointer_to_current(&q))->a,
	   ((SomeType *)pointer_to_current(&q))->buf,
	   current_priority(&q));
    next_element(&q);
  }
  printf("Destroying queue.\n");
  destroy_queue(&q);
  printf("Queue contains:\n");
  while (! end_of_queue(&q)) {
    printf("%d %s with priority %d\n", 
	   ((SomeType *)pointer_to_current(&q))->a,
	   ((SomeType *)pointer_to_current(&q))->buf,
	   current_priority(&q));
    next_element(&q);
  }
}