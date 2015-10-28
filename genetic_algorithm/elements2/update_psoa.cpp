		for( int i=0; i<par.pop_size; i++ )
			update_particle(P, i, g, par);
		update_global(P, g);
		print_population(P, par);
