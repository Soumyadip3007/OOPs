import numpy as np
from scipy.ndimage import gaussian_filter

class SSIM:
    def __init__(self, window_size=11, sigma=1.5):
        self.window_size = window_size
        self.sigma = sigma
        self.window = self.create_gaussian_window(window_size, sigma)

    def create_gaussian_window(self, size, sigma):
        """Create a Gaussian window."""
        ax = np.arange(-size // 2 + 1., size // 2 + 1.)
        xx, yy = np.meshgrid(ax, ax)
        kernel = np.exp(-0.5 * (np.square(xx) + np.square(yy)) / np.square(sigma))
        return kernel / np.sum(kernel)

    def ssim(self, img1, img2):
        """Compute SSIM between two images."""
        K1, K2, L = 0.01, 0.03, 255  # Constants in the SSIM formula
        C1, C2 = (K1 * L) ** 2, (K2 * L) ** 2

        # Apply Gaussian filter
        mu1 = gaussian_filter(img1, self.sigma)
        mu2 = gaussian_filter(img2, self.sigma)
        mu1_sq = mu1 ** 2
        mu2_sq = mu2 ** 2
        mu1_mu2 = mu1 * mu2

        sigma1_sq = gaussian_filter(img1 ** 2, self.sigma) - mu1_sq
        sigma2_sq = gaussian_filter(img2 ** 2, self.sigma) - mu2_sq
        sigma12 = gaussian_filter(img1 * img2, self.sigma) - mu1_mu2

        # SSIM formula
        ssim_map = ((2 * mu1_mu2 + C1) * (2 * sigma12 + C2)) / ((mu1_sq + mu2_sq + C1) * (sigma1_sq + sigma2_sq + C2))
        return ssim_map.mean()

if __name__ == "__main__":
    import cv2

    # Load example images
    img1 = cv2.imread('C:\Users\skar0\Downloads\Images\Images\hotanairport1-rgb.jpg', cv2.IMREAD_GRAYSCALE)
    img2 = cv2.imread('C:\Users\skar0\Downloads\Images\Images\hotanairport5.jpg', cv2.IMREAD_GRAYSCALE)

    # Check if images are loaded
    if img1 is None or img2 is None:
        raise FileNotFoundError("One of the images was not found.")

    # Compute SSIM
    ssim_calculator = SSIM()
    ssim_index = ssim_calculator.ssim(img1, img2)

    print(f'SSIM Index: {ssim_index}')