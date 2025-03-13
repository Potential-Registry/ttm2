config  =  {
    'debug_print': True,
    'wrap_potential': True,
    'function_name': '__ttm2f_mod_MOD_ttm2f', 
    'shim_script': 'double derivs[nwaters*3*3]; // allocate space for the derivatives', 
    'arguments': (('nwaters', 'int'), {'name': 'raw_coords', 'dtype': 'FlatCoordinates'}, {'name': 'derivs', 'dtype': 'double*', 'ref': False, 'extra': False}, {'name': 'energy', 'dtype': 'double', 'ref': True, 'extra': False}, ('imodel', 'int')), 'requires_make': True, 
    'fortran_potential': True, 'transpose_call': False, 'name': 'ttm2', 'potential_source': '/config/potentials/ttm2/raw_source/ttm2', 
    'static_source': False
}
