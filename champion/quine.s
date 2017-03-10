.name "quine"
.comment "dr_quine ;)"

start:	st		r1,13				# 5
		ld		%4,r7				# 5

live:	live	%1					# 10
		ld		%0,r3				# 5

while:	ldi		%:live,r3,r9		# 10
		sub		r9,r5,r6			# 10
		zjmp	%400				# 20
		add		r3,r7,r3			# 10
		sti		r9,%400,r3			# 25
		add		r8,r8,r8			# 10
		zjmp	%:while				# 20
