<template>
  <div id="disqus_thread"></div>
</template>

<script>
  export default {
    props: {
      pageUuid: {
        type: String,
        required: true,
        validator(uuid) {
          const pattern =
            /^[0-9a-f]{8}-[0-9a-f]{4}-[1-5][0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}$/i;
          
          return pattern.test(uuid);
        }
      },
      
      pageTitle: {
        type: String,
        required: true
      }
    },
    
    computed: {
      forumShortname() {
        return location.hostname === "localhost"
               ? "vuepress-testing"
               : "oop-course";
      },
      
      pageUrl() {
        return location.origin + location.pathname;
      }
    },
    
    methods: {
      install() {
        const self = this;
        
        window.disqus_config = function() {
          self.configure(this);
        };
        
        const script = document.createElement("script");
        script.setAttribute("data-timestamp", Date.now().toString());
        script.src = `https://${this.forumShortname}.disqus.com/embed.js`;
        script.type = "text/javascript";
        script.async = true;
        
        (document.head || document.body).appendChild(script);
      },
      
      reset() {
        const self = this;
        
        const observer = new MutationObserver(() => {
          observer.disconnect();
          
          window.DISQUS.reset({
            reload: true,
            config: function() {
              self.configure(this);
            }
          });
        });
        
        const target = document.getElementsByTagName("title")[0];
        const config = {childList: true};
        
        observer.observe(target, config);
      },
      
      configure(disqus) {
        const page = disqus.page;
        page.identifier = this.pageUuid;
        page.url = this.pageUrl;
        page.title = this.pageTitle;
      }
    },
    
    mounted() {
      window.DISQUS === undefined ? this.install() : this.reset();
    }
  };
</script>

<style scoped>
  #disqus_thread {
    margin-top: 5rem;
  }
</style>