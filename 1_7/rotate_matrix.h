class Solution
{
public:
    static bool rotateMatrix(int image[], int width, int height)
    {
        if (width != height)
            return false;
        int n = width;
        for (int layer = 0; layer < n / 2; layer++)
        {
            int first = layer;
            int last = n - 1 - layer;
            for (int i = first; i < last; i++)
            {
                int temp = image[layer * width + i];
                image[layer * width + i] = image[i * width + last];
                image[i * width + last] = image[last * width + (last - i)];
                image[last * width + (last - i)] = image[(last - i) * width + layer];
                image[(last - i) * width + layer] = temp;
            }
        }
    }
};