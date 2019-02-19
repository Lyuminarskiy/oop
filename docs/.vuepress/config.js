const path = require("path");

module.exports = {
  head: [
    [
      "meta", {
      name: "author",
      content: "Владислав Люминарский"
    }
    ],
    [
      "meta", {
      name: "theme-color",
      content: "#3eaf7c"
    }
    ],
    [
      "link", {
      rel: "icon",
      href: "/icons/icon512.png"
    }
    ],
    [
      "link", {
      rel: "manifest",
      href: "/manifest.webmanifest"
    }
    ],
    [
      "link", {
      rel: "license",
      href: "/LICENSE"
    }
    ]
  ],
  locales: {
    "/": {
      lang: "ru-RU",
      title: "ООП",
      description: "Учебные материалы по курсу " +
                   "\"Объектно-ориентированное программирование\""
    },
    "/en/": {
      lang: "en-US",
      title: "OOP",
      description: "Educational materials for course " +
                   "\"Object-oriented programming\""
    }
  },
  themeConfig: {
    locales: {
      "/": {
        selectText: "Выбор языка",
        label: "Русский",
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
            "01/"
          ],
          "/labs/": [
            "01/"
          ]
        },
        lastUpdated: "Последнее обновление",
        repo: "OOP-course/OOP-course",
        docsDir: "docs",
        editLinks: true,
        editLinkText: "Редактировать эту страницу",
        serviceWorker: {
          updatePopup: {
            message: "Доступно новое содержимое.",
            buttonText: "Обновить"
          }
        }
      },
      "/en/": {
        selectText: "Languages",
        label: "English",
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
            text: "Labs",
            link: "/en/labs/"
          }
        ],
        sidebar: {
          "/en/practice/": [
            "01/"
          ],
          "/en/labs/": [
            "01/"
          ]
        },
        lastUpdated: "Last updated",
        docsDir: "docs/en",
        editLinks: true,
        editLinkText: "Edit this page",
        serviceWorker: {
          updatePopup: {
            message: "New content is available.",
            buttonText: "Refresh"
          }
        }
      }
    },
    repo: "OOP-course/OOP-course",
    algolia: {
      apiKey: "892ad28dc056e1eb225c126678ef1c09",
      indexName: "c_vladislav",
      algoliaOptions: {
        facetFilters: ["tags:oop"]
      }
    },
    evergreen: true
  }
};