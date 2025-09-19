# wrap()

## Description:
The wrap() function constrains a value to a specified range (min_val, max_val) by “wrapping” it around.<br>
If the value exceeds the maximum, it wraps back to the minimum, and if it is below the minimum,<br>
it wraps back from the maximum

## Syntax:
```c
wrap(x, min_val, max_val);
```
### wrap()
- **Desc:** the actual function
- **Return:** *long long* ( the wraped value of X )

### x: 
- **Desc:** number to wrap
- **Type:** *long long*

### min_val: 
- **Desc:** minimum value of the target range
- **Type:** *long long*

### max_val: 
- **Desc:** max number of prime factors to calculate
- **Type:** *long long*
