[⌫ back](README.md)

# Algorithms
I wrote down all the [algorithms](algorithms.pdf) that we learned and proved during the course from the course literature *Self-Stabilization* by Shlomi Dolev.

## Concepts
### Self-stabilizing systems requirements
 - Starting in any arbitrary configuration will eventually reach a safe configuration and results in a desired legal behaviour
   - Legal behaviour
     - Set of legal executions (LE) which are defined for a specific system and task
   - Safe configuration
     - Every fair execution, with regards to LE, of an algorithm that start from c belongs to LE
       - An execution of a self-stabilizing system has a suffix that appears in LE
     - Every fair execution of the algorithm reaches a safe configuration with relation to LE
       - Fair execution implies that every step that is applicable infinitely often is executed infinitely often

