#ifndef CONTROLLERS_TEXTURE_MANAGER_HPP
#define CONTROLLERS_TEXTURE_MANAGER_HPP

namespace controllers {
    class TextureManager {
        private:
		    static TextureManager* P_SHARED_INSTANCE;

	    private:
		    TextureManager();
		    TextureManager(TextureManager const&);
		    TextureManager& operator = (TextureManager const&);

	    public:
		    static TextureManager* getInstance();
    };
}

#endif