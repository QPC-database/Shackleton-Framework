/*
 ============================================================================
 Name        : evolution.h
 Author      : Hannah M. Peeler
 Version     : 1.0
 Copyright   : 
 
    Copyright 2019 Arm Inc., Andrew Sloss, Hannah Peeler

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

    Please refer to 
    https://github.com/ARM-software/Shackleton-Framework/blob/master/LICENSE.TXT
    for a full overview of the license covering this work.
    
 Description : Core file for pulling all evolutionary
               capabilities together into 1 file

               Will include initialization and manipulation
               of the population based on what parameters are
               provided to main
 ============================================================================
 */

#ifndef EVOLUTION_EVOLUTION_H_
#define EVOLUTION_EVOLUTION_H_

/*
 * IMPORT
 */

#include "mutation.h"
#include "crossover.h"
#include "generation.h"
#include "selection.h"

/*
 * ROUTINES
 */

/*
 * NAME
 *
 *   evolution_basic_crossover_and_mutation
 *
 * DESCRIPTION
 *
 *  Completes an evolutionary process in which num_gens
 *  generations are created, each pop_size number of individuals 
 *  within them. During each generation, each individual will have
 *  a mut_perc/100 chance of being mutated and have a cross_perc/100 
 *  chance of being crossed with another individual
 *
 * PARAMETERS
 *
 *  uint32_t num_gens -- number of generations to be created/gone through
 *  uint32_t pop_size -- target size of the populations
 *  uint32_t indiv_size -- number of nodes in a single individual
 *  uint32_t tourn_size -- size of tournaments
 *  uint32_t mut_perc -- percentage chance of being mutated during each generation
 *  uint32_t cross_perc -- percentage chance of being a part of a crossover during each generation
 *  osaka_object_typ ot -- osaka object type to be used in the run
 *  bool vis -- whether or not visualization is enabled
 *
 * RETURN
 *
 *  node_str* - best individual in final generation
 *
 * EXAMPLE
 *
 * node_str* best = evolution_basic_crossover_and_mutation(20, 50, 50, 2, 5, 25, LLVM_PASS, true);
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

node_str* evolution_basic_crossover_and_mutation(uint32_t num_gens, uint32_t pop_size, uint32_t indiv_size, uint32_t tourn_size, uint32_t mut_perc, uint32_t cross_perc, osaka_object_typ ot, bool vis, char* file);

/*
 * NAME
 *
 *   evolution_basic_crossover_and_mutation_with_replacement
 *
 * DESCRIPTION
 *
 *  Completes an evolutionary process in which num_gens
 *  generations are created, each pop_size number of individuals 
 *  within them. During each generation, each individual will have
 *  a mut_perc/100 chance of being mutated and have a cross_perc/100 
 *  chance of being crossed with another individual. It is the same as 
 *  the other basic crossover and mutation method, but individuals
 *  can be chosen multiple times
 *
 * PARAMETERS
 *
 *  uint32_t num_gens -- number of generations to be created/gone through
 *  uint32_t pop_size -- target size of the populations
 *  uint32_t indiv_size -- number of nodes in a single individual
 *  uint32_t tourn_size -- size of tournaments
 *  uint32_t mut_perc -- percentage chance of being mutated during each generation
 *  uint32_t cross_perc -- percentage chance of being a part of a crossover during each generation
 *  osaka_object_typ ot -- osaka object type to be used in the run
 *  bool vis -- whether or not visualization is enabled
 *
 * RETURN
 *
 *  node_str* - best individual in final generation
 *
 * EXAMPLE
 *
 * node_str* best = evolution_basic_crossover_and_mutation_with_replacement(20, 50, 50, 2, 5, 25, LLVM_PASS, true);
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

node_str* evolution_basic_crossover_and_mutation_with_replacement(uint32_t num_gens, uint32_t pop_size, uint32_t indiv_size, uint32_t tourn_size, uint32_t mut_perc, uint32_t cross_perc, osaka_object_typ ot, bool vis, char* file, bool cache);

#endif /* EVOLUTION_EVOLUTION_H_ */