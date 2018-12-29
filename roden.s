.name "Roden"
.comment "Some comment"

live:
live %15
ld %5, r5
ld %5, r5
ld %5, r5
ld %5, r5
live %15
zjmp %100
zjmp %100
zjmp %100
fork %100
live %20
zjmp %20
fork %15
st r7, 10
st r7, 10
st r7, 10
st r7, 10
st r7, 10
st r7, 10
add r15, r15, r15
add r15, r15, r15
zjmp %100
add r15, r15, r15
add r15, r15, r15
fork %:live
live %15
