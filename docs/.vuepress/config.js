module.exports = {
  ga: "UA-138493396-3",
  evergreen: true,
  serviceWorker: true,
  head: [
    ["meta", {
      name: "author",
      content: "Владислав Люминарский"
    }],
    ["meta", {
      name: "theme-color",
      content: "#3eaf7c"
    }],
    ["link", {
      rel: "icon",
      href: "/icons/icon512.png"
    }],
    ["link", {
      rel: "manifest",
      href: "/manifest.webmanifest"
    }],
    ["link", {
      rel: "license",
      href: "/LICENSE"
    }]
  ],
  locales: {
    "/": {
      lang: "ru-RU",
      title: "Объектно-ориентированное программирование",
      description: "Учебные материалы по курсу " +
                   "\"Объектно-ориентированное программирование\"."
    },
    "/en/": {
      lang: "en-US",
      title: "Object-oriented programming",
      description: "Educational materials for course " +
                   "\"Object-oriented programming\"."
    }
  },
  themeConfig: {
    repo: "OOP-course/OOP-course",
    editLinks: true,
    logo: "/icons/icon512.png",
    locales: {
      "/": {
        docsDir: "docs",
        selectText: "Выбор языка",
        label: "Русский",
        lastUpdated: "Последнее обновление",
        editLinkText: "Редактировать эту страницу",
        serviceWorker: {
          updatePopup: {
            message: "Доступно новое содержимое.",
            buttonText: "Обновить"
          }
        },
        algolia: {
          apiKey: "892ad28dc056e1eb225c126678ef1c09",
          indexName: "c_vladislav",
          algoliaOptions: {
            facetFilters: [
              "lang:ru-RU",
              "tags:oop-course"
            ]
          }
        },
        nav: [
          {
            text: "О курсе",
            link: "/about/"
          },
          {
            text: "Практика",
            link: "/practice/"
          },
          {
            text: "Лабораторные",
            link: "/labs/"
          }
        ],
        sidebar: {
          "/practice/": [
            "",
            {
              title: "Основы ООП",
              collapsable: false,
              children: [
                "01/",
                "02/"
              ]
            },
            {
              title: "Основы проектирования ПО",
              collapsable: false,
              children: [
                "03/",
                "04/"
              ]
            }
          ],
          "/labs/": [
            "",
            {
              title: "Лабораторные работы",
              collapsable: false,
              children: [
                "01/",
                "02/"
              ]
            }
          ]
        }
      },
      "/en/": {
        docsDir: "docs/en",
        selectText: "Languages",
        label: "English",
        lastUpdated: "Last updated",
        editLinkText: "Edit this page",
        serviceWorker: {
          updatePopup: {
            message: "New content is available.",
            buttonText: "Refresh"
          }
        },
        algolia: {
          apiKey: "892ad28dc056e1eb225c126678ef1c09",
          indexName: "c_vladislav",
          algoliaOptions: {
            facetFilters: [
              "lang:en-US",
              "tags:oop-course"
            ]
          }
        },
        nav: [
          {
            text: "About",
            link: "/en/about/"
          },
          {
            text: "Practice",
            link: "/en/practice/"
          },
          {
            text: "Laboratory",
            link: "/en/labs/"
          }
        ],
        sidebar: {
          "/en/practice/": [
            "",
            {
              title: "Basics of OOP",
              collapsable: false,
              children: [
                "01/",
                "02/"
              ]
            },
            {
              title: "Basics of software design",
              collapsable: false,
              children: [
                "03/",
                "04/"
              ]
            }
          ],
          "/en/labs/": [
            "",
            {
              title: "Laboratory work",
              collapsable: false,
              children: [
                "01/",
                "02/"
              ]
            }
          ]
        }
      }
    }
  }
};